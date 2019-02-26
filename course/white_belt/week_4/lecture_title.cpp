#include <string>

using std::string;

struct Specialization {
    explicit Specialization(const string& v)
        : value(v)
    {}
    string value;
};

struct Course {
    explicit Course(const string& v)
        : value(v)
    {}
    string value;
};

struct Week {
    explicit Week(const string& v)
        : value(v)
    {}
    string value;
};

struct LectureTitle {
    LectureTitle(const Specialization& s, const Course& c, const Week& w)
        : specialization(s.value)
        , course(c.value)
        , week(w.value)
    {}
    string specialization;
    string course;
    string week;
};

int main() {
    LectureTitle lt(Specialization("C++"), Course("White belt"), Week("4th"));

    return 0;
}
