#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;


class LRUCache {
private:
    size_t size_;
    unordered_map<int, list<pair<int, int> >::iterator> cache;
    list<pair<int, int> > recent;
public:
    LRUCache(size_t size): size_(size) {}

    int get(int key) {
        auto found_iter = cache.find(key);
        if (found_iter == cache.end())
            return -1;
        recent.splice(recent.begin(), recent, found_iter->second);
        return found_iter->second->second;
    }

    void set(int key, int value) {
        auto found_iter = cache.find(key);
        if (found_iter != cache.end()) {
            recent.splice(recent.begin(), recent, found_iter->second);
            found_iter->second->second = value;
            return;
        }

        if (cache.size() == size_) {
            int old_key = recent.back().first;
            recent.pop_back();
            cache.erase(old_key);
        }
        recent.emplace_front(key, value);
        cache[key] = recent.begin();
    }
};


int main() {
    LRUCache cache(2);

    cache.set(2,2);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cache.set(1,1);
    cache.set(1,5);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    cache.set(8,8);
    cout << cache.get(1) << endl;
    cout << cache.get(8) << endl;
}
