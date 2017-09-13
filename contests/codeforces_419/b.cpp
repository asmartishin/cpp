#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point {
    bool point;
    bool start;
    int question_id;

    Point(bool point, bool start, int question_id) : point(point), start(start), question_id(question_id) { }
};


int main() {
    int n, k, q, ts, te, ks = 0;
    set<int> question_ids;

    vector<vector<Point> > temperatures(200000);

    cin >> n >> k >> q;

    vector<int> result(q);
    bool decrease = false;
    int remove_id = 0;

    for (size_t i = 0; i < q; ++i) {
        result[i] = 0;
    }


    for (size_t i = 0; i < n; ++i) {
        cin >> ts >> te;
        temperatures[ts].push_back(Point(true, true, 0));
        temperatures[te].push_back(Point(true, false, 0));
    }

    for (size_t i = 0; i < q; ++i) {
        cin >> ts >> te;
        temperatures[ts].push_back(Point(false, true, i));
        temperatures[te].push_back(Point(false, false, i));
    }

    for (size_t i = 0; i < 200000; ++i) {
        for (size_t j = 0; j < temperatures[i].size(); ++j) {
            if (temperatures[i][j].point) {
                if (temperatures[i][j].start) {
                    ++ks;
                } else {
                    decrease = true;
                }
            } else {
                if (temperatures[i][j].start) {
                    question_ids.insert(temperatures[i][j].question_id);
                } else {
                    remove_id = temperatures[i][j].question_id;
                }
            }
        }

        for(auto qi : question_ids) {
            if (ks >= k) {
                ++result[qi];
            }
        }

        if (remove_id) {
            question_ids.erase(remove_id);
            remove_id = 0;
        }

        if (decrease) {
            --ks;
            decrease = false;
        }
    }

    for (size_t i = 0; i < q; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
