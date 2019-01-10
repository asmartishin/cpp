#include <cstdio>
#include <string>

using namespace std;


class StringBuf {
public:
    StringBuf(const char * data, size_t len)
        : Data_(data)
        , Length_(len)
    {}

    const char * Data() const noexcept {
        return Data_;
    }

    size_t Length() const noexcept {
        return Length_;
    }

private:
    const char * Data_;
    size_t Length_;
};

int main() {
    char s[] = "tag1=asd;tag2=dsa";

    StringBuf s1{s, 4};
    StringBuf s2{s + 9, 4};

    fprintf(stderr, "%.*s\n", (int)s1.Length(), s1.Data());
    fprintf(stderr, "%.*s\n", (int)s2.Length(), s2.Data());

    return 0;
}
