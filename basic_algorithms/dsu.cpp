#include <iostream>
#include <vector>

using namespace std;


void MakeSet(vector<int> &parent, vector<int> &rank, int a) {
    parent[a] = a;
    rank[a] = 0;
}


int Find(vector<int> &parent, int a) {
    while (a != parent[a])
        a = parent[a];
    return a;
}


void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = Find(parent, a);
    b = Find(parent, b);

    if (a == b)
        return;

    if (rank[a] > rank[b])
        parent[b] = a;
    else {
        parent[a] = b;
        if (rank[a] == rank[b])
            ++rank[b];
    }
}

void PrintDSU(vector<int> &parent, vector<int> &rank) {
    for (size_t i = 1; i < parent.size(); ++i) {
        cout << i << ' ' << parent[i] << ' ' << rank[i] << endl;
    }
    cout << endl;
}


int main() {
    vector<int> parent(13);
    vector<int> rank(13);

    for (size_t i = 1; i <= 12; ++i)
        MakeSet(parent, rank, i);

    Union(parent, rank, 2, 10);
    Union(parent, rank, 7, 5);
    Union(parent, rank, 6, 1);
    Union(parent, rank, 3, 4);
    Union(parent, rank, 5, 11);
    Union(parent, rank, 7, 8);
    Union(parent, rank, 7, 3);
    Union(parent, rank, 12, 2);
    Union(parent, rank, 9, 6);

    PrintDSU(parent, rank);

    return 0;
}
