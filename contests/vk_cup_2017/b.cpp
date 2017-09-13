#include <iostream>
#include <unordered_set>
#include <unordered_map>


using namespace std;

void depth_fast_search(
    unordered_map<long long int, unordered_set<long long int> >& friends,
    const int id,
    unordered_set<long long int>& visited
) {
    if (visited.count(id) > 0) {
        return;
    } else {
        visited.insert(id);
        for (auto it = friends[id].begin(); it != friends[id].end(); ++it) {
            depth_fast_search(friends, *it, visited);
        }
    }
}

bool check_clique(
    unordered_map<long long int, unordered_set<long long int> >& friends,
    unordered_set<long long int>& subset
) {
    for (auto it = subset.begin(); it != subset.end(); ++it) {
        for (auto it2 = subset.begin(); it2 != subset.end(); ++it2) {
            if (*it != *it2 && friends[*it].count(*it2) == 0) {
                return false;
            }
        }
    }
    return true;
}


int main () {
    long long int n,m;
    cin >> n >> m;

    unordered_set<long long int> people;
    unordered_map<long long int, unordered_set<long long int> > friends;
    for (size_t i = 0; i < m; ++i) {
        long long int a,b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
        people.insert(a);
        people.insert(b);
    }

    while (people.size() > 0) {
        unordered_set<long long int> visited;
        long long int person = *(people.begin());
        depth_fast_search(friends, person, visited);
        bool is_clique = check_clique(friends, visited);
        if (!is_clique) {
            cout << "NO" << endl;
            return 0;
        }
        for (auto it = visited.begin(); it != visited.end(); ++it) {
            people.erase(*it);
        }
    }

    cout << "YES" << endl;

    return 0;
}
