#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>

typedef long long int TScore;
typedef long long int TVolume;

class TVideoCSResponse;

struct EPCS {
    int EP;
    int CS;

    EPCS(const int EP, const int CS)
    : EP(EP)
    , CS(CS)
    {}

    bool operator==(const EPCS& other) const {
        return EP == other.EP && CS == other.CS;
    }

    bool operator!=(const EPCS& other) const {
        return !(*this == other);
    }
};

struct EPCSHash {
    size_t operator() (const EPCS& epcs) const {
        return std::hash<int>()(epcs.EP) ^ std::hash<int>()(epcs.CS);
    }
};

struct TVideoCS {
    int Video;
    int CS;

    TVideoCS(const int Video, const int CS)
    : Video(Video)
    , CS(CS)
    {}

    bool operator==(const TVideoCS& other) const {
        return Video == other.Video && CS == other.CS;
    }

    bool operator!=(const TVideoCS& other) const {
        return !(*this == other);
    }

};

struct TVideoCSHash {
    size_t operator() (const TVideoCS& videoCS) const {
        return std::hash<int>()(videoCS.Video) ^ std::hash<int>()(videoCS.CS);
    }
};

struct TEPVideo {
    int EP;
    int Video;
    TEPVideo(const int EP, const int Video)
    : EP(EP)
    , Video(Video)
    {}
 bool operator==(const TEPVideo& other) const {
  return Video == other.Video && EP == other.EP;
 }

 bool operator!=(const TEPVideo& other) const {
  return !(*this == other);
 }

};

struct TEPVideoHash {
    size_t operator() (const TEPVideo& video) const {
        return std::hash<int>()(video.Video) ^ std::hash<int>()(video.EP);
    }
};

class TEPVideoDuration {
public:
    bool RefreshMaxDuration(const int EP, const int Video, const TScore duration) {
        if (!EPVideoScore.count(TEPVideo(EP, Video))) {
            EPVideoScore[TEPVideo(EP, Video)] = 10000000000;
        }
        if (EPVideoScore[TEPVideo(EP, Video)] < duration) {
            EPVideoScore[TEPVideo(EP, Video)] = duration;
            return true;
        } else {
            return false;
        }
    }
private:
    std::unordered_map<TEPVideo, TScore, TEPVideoHash> EPVideoScore;
};

class TVideoTimings {
public:
    void SetEPCSTime(const int EP, const int CS, const TScore& time) {
        EPCSTime[EPCS(EP, CS)] = time;
        EPCSs[EP].insert(CS);
        CSEPs[CS].insert(EP);
    }

    void SetEPDCTime(const int EP, const TScore& time) {
        TimeToDC[EP] = time;
    }

    TScore GetEPCSTime(const int EP, const int CS) const {
        return EPCSTime.at(EPCS(EP, CS));
    }

    TScore GetEPDCTime(const int EP) const {
        return TimeToDC.at(EP);
    }

    void SetEPCount(const int EPCount) {
        EPCSs = std::vector<std::unordered_set<int> > (EPCount);
        TimeToDC = std::vector<TScore> (EPCount);
    }

    void SetCSCount(const int SCCount) {
        CSEPs = std::vector<std::unordered_set<int> > (SCCount);
    }

    TScore GetTimeDiff(const int EP, const int CS) const {
        return GetEPDCTime(EP) - GetEPCSTime(EP, CS);
    }

    std::unordered_set<int>::const_iterator CSOfEPBegin(const int EP) const {
        return EPCSs.at(EP).begin();
    }

    std::unordered_set<int>::const_iterator CSOfEPEnd(const int EP) const {
        return EPCSs.at(EP).end();
    }

    std::unordered_set<int>::const_iterator EPOfCSBegin(const int CS) const {
        return CSEPs.at(CS).begin();
    }

    std::unordered_set<int>::const_iterator EPOfCSEnd(const int CS) const {
        return CSEPs.at(CS).end();
    }
private:
    std::vector<std::unordered_set<int> > EPCSs;
    std::vector<std::unordered_set<int> > CSEPs;
    std::vector<TScore> TimeToDC;
    std::unordered_map<EPCS, TScore, EPCSHash> EPCSTime;
};

struct TVideoCSInfo {
    int Video;
    int CS;
    TVolume Volume;
    TScore Score;

    TVideoCSInfo()
        : Video()
        , CS()
        , Volume()
        , Score()
    {}

    TVideoCSInfo(const int video, const int cs, const int volume, const int score)
        : Video(video)
        , CS(cs)
        , Volume(volume)
        , Score(score)
    {}

};

struct TRequest {
    int EP;
    int Video;
    int RequestsCount;

    TRequest()
        : EP()
        , Video()
        , RequestsCount()
    {}

    TRequest(const int ep, const int video, const int requestsCount)
        : EP(ep)
        , Video(video)
        , RequestsCount(requestsCount)
    {}
};

class TRequestReader {
public:
    void AddRequest(const TRequest& request) {
        Requests.push_back(request);
    }

    std::vector<TRequest>::const_iterator Begin() const {
        return Requests.begin();
    }

    std::vector<TRequest>::const_iterator End() const {
        return Requests.end();
    }
private:
    std::vector<TRequest> Requests;
};

class TVideoCSResponse {
private:
    std::vector<TVolume> VideoToVol;
    std::vector<TVolume> CSToVol;
    std::vector<std::vector<int> > CSToVideo;
    TScore TotalScore;

public:
    void SetCSCount(const size_t csSize) {
        CSToVol = std::vector<TVolume>(csSize);
        CSToVideo = std::vector<std::vector<int> >(csSize, std::vector<int>());
    }

    void SetVideoCount(const size_t videoCount) {
        VideoToVol = std::vector<TVolume>(videoCount);
    }

    void AddVideo(const int video, const int vol) {
        VideoToVol[video] = vol;
    }

    void AddCS(const int CS, const int vol) {
        CSToVol[CS] = vol;
    }

    bool CheckAddVideoToCS(const int video, const int CS) const  {
        return CSToVol[CS] >= VideoToVol[video];
    }

    void AddVideoToCS(const int video, const int CS, const TScore score) {
        CSToVideo[CS].push_back(video);
        CSToVol[CS] -= VideoToVol[video];
        TotalScore += score;
    }

    void Dump(const std::string fileName) {
        std::ofstream out(fileName);
        int usedCSCount = 0;
        for (size_t cs = 0; cs < CSToVol.size(); ++cs) {
            if (CSToVideo.size()) {
                ++usedCSCount;
            }
        }
        out << usedCSCount << std::endl;

        for (size_t cs = 0; cs < CSToVideo.size(); ++cs) {
            out << cs;
            for (size_t v = 0; v < CSToVideo[cs].size(); ++v) {
                out << " " << CSToVideo[cs][v];
            }
            out << std::endl;
        }
        out.close();
        std::cout << TotalScore << std::endl;
    }

    TVolume GetVideoVolume(const int video) const {
        return VideoToVol[video];
    }
};


class TVideoScheme {
    public:
        TVideoScheme(const std::string& filename, TVideoTimings& videoTimings, TRequestReader& requestReader, TVideoCSResponse& videoCSResponse) {
            std::ifstream inFile(filename);

            TScore latency;
            int CSConnections;
            int CS;
            int requests;
            int video;
            int endpoint;

            numVideos = 0;
            inFile >> numVideos;
            inFile >> numEndpoints;
            inFile >> numRequests;
            inFile >> numCacheServers;
            inFile >> volume;

            videoCSResponse.SetVideoCount(numVideos);
            videoCSResponse.SetCSCount(numCacheServers);

            videoTimings.SetEPCount(numEndpoints);
            videoTimings.SetCSCount(numEndpoints);


            for (size_t x = 0; x < numCacheServers; ++x) {
                 videoCSResponse.AddCS(x, volume);
            }

            for (size_t x = 0; x < numVideos; ++x) {
                inFile >> volume;
                videoCSResponse.AddVideo(x, volume);
            }

            for (size_t x = 0; x < numEndpoints; ++x) {
                inFile >> latency;
                inFile >> CSConnections;

                videoTimings.SetEPDCTime(x, latency);

                if  (CSConnections > 0) {
                    for (size_t y = 0; y < CSConnections; ++y) {
                        inFile >> CS;
                        inFile >> latency;

                        videoTimings.SetEPCSTime(x, CS, latency);
                    }
                }
            }

            for (size_t x = 0; x < numRequests; ++x) {
                inFile >> video;
                inFile >> endpoint;
                inFile >> requests;

                requestReader.AddRequest(TRequest(endpoint, video, requests));
            }
            inFile.close();
        }

    private:
        int numVideos; // V - number of videos
        int numEndpoints; // E - number of endpoints
        int numRequests; // R - number of request descriptions
        int numCacheServers ; // C - number of cache servers
        TVolume volume; // X - the capacity of each cache server in megabytes
};


bool VideoCSInfoComparator1(const TVideoCSInfo& first, const TVideoCSInfo& second) {
    return first.Score > second.Score || (first.Score == second.Score && first.Volume < second.Volume);
}

class TVideoCSIndex {
public:
    TVideoCSIndex(const TVideoTimings& videoTimings, const TRequestReader& requestReader, TVideoCSResponse& videoCSResponse, TEPVideoDuration& EPVideoDuration)
    : VideoTimings(videoTimings)
    , RequestReader(requestReader)
    , VideoCSResponse(videoCSResponse)
    , EPVideoDuration(EPVideoDuration)
    {
        for (
            auto it = RequestReader.Begin();
            it != RequestReader.End();
            ++it
        ) {
            UpdateScore(*it);
        }
    }

    void AddScore(const TVideoCS& videoCS, const TScore& score) {
        if (VideoSCScore.count(videoCS) == 0) {
            VideoSCScore[videoCS] = 0;
        }
        VideoSCScore[videoCS] += score;
    }

    void UpdateScore(const TRequest& request) {
        for(
            auto it = VideoTimings.CSOfEPBegin(request.EP);
            it != VideoTimings.CSOfEPEnd(request.EP);
            ++it
        ) {
            int CS = *it;
            AddScore(TVideoCS(request.Video, CS), VideoTimings.GetTimeDiff(request.EP, CS) * request.RequestsCount);
        }
    }

    void PlaceVideos() {
        std::vector<TVideoCSInfo> videoCSInfo;
        for(
            auto it = VideoSCScore.begin();
            it != VideoSCScore.end();
            ++it
        ) {
            videoCSInfo.push_back(TVideoCSInfo(it->first.Video, it->first.CS, VideoCSResponse.GetVideoVolume(it->first.Video), it->second));
        }
        std::sort(videoCSInfo.begin(), videoCSInfo.end(), VideoCSInfoComparator1);
        for(
            auto it = videoCSInfo.begin();
            it != videoCSInfo.end();
            ++it
        ) {
            if (VideoCSResponse.CheckAddVideoToCS(it->Video, it->CS)) {
                bool IsVideoBetterForAnyOne = false;
                for (
                    auto it2 = VideoTimings.EPOfCSBegin(it->CS);
                    it2 != VideoTimings.EPOfCSEnd(it->CS);
                    ++it2
                ) {
                    if (EPVideoDuration.RefreshMaxDuration(*it2, it->Video, it->Score)) {
                        IsVideoBetterForAnyOne = true;
                    }
                }
                if (IsVideoBetterForAnyOne) {
                    VideoCSResponse.AddVideoToCS(it->Video, it->CS, it->Score);
                }
            }
        }
    }
private:
    std::unordered_map<TVideoCS, TScore, TVideoCSHash> VideoSCScore;
    const TVideoTimings& VideoTimings;
    const TRequestReader& RequestReader;
    TVideoCSResponse& VideoCSResponse;
    TEPVideoDuration& EPVideoDuration;
};

int main() {
    std::string file_name("trending_today");
    std::string input_file_name(file_name + std::string(".in"));
    std::string output_file_name(file_name + std::string(".out"));
    TVideoTimings videoTimings;
    TRequestReader requestReader;
    TVideoCSResponse videoCSResponse;
    TVideoScheme videoScheme(input_file_name, videoTimings, requestReader, videoCSResponse);
    TEPVideoDuration EPVideoDuration;
    TVideoCSIndex videoCSIndex(videoTimings, requestReader, videoCSResponse, EPVideoDuration);
    videoCSIndex.PlaceVideos();
    videoCSResponse.Dump(output_file_name);
    return 0;
}
