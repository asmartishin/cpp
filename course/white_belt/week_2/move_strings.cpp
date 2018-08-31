#include <iostream>
#include <vector>
#include <string>

using Strings = std::vector<std::string>;

void MoveStrings(Strings& source, Strings& destination) {
    destination.reserve(destination.size() + source.size());
    destination.insert(destination.end(), source.begin(), source.end());
    source.clear();
}

int main() {
    Strings source{"asd", "dsa"};
    Strings destination{"zay", "sdf"};

    MoveStrings(source, destination);

    return 0;
}
