#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class RandomizedSet {
private:
    vector<int> values_;
    unordered_map<int, int> m_values_;
public:
    RandomizedSet() {};
    bool insert(int val) {
        if (m_values_.find(val) == m_values_.end()) {
            values_.push_back(val);
            m_values_[val] = values_.size() - 1;
            return true;
        }

        return false;
    }

    bool remove(int val) {
        if (m_values_.find(val) != m_values_.end()) {
            int index = m_values_[val];
            if (index == values_.size() - 1) {
                values_.pop_back();
            } else {
                swap(values_[index], values_.back());
                values_.pop_back();
                m_values_[values_[index]] = index;
            }
            m_values_.erase(val);
            return true;
        }

        return false;
    }

    int getRandom() {
        int index = rand() % values_.size();
        return values_[index];
    }

    void print() {
        for (const auto &v: m_values_)
            cout << '(' <<v.first << ',' << v.second << ')' << ' ';
        cout << endl;
        for (const auto &v: values_)
            cout << v << ' ';
        cout << endl;
    }
};


int main() {
    RandomizedSet rs;
    rs.insert(0);
    rs.print();

    rs.remove(0);
    rs.print();

    rs.insert(-1);
    rs.print();

    rs.remove(0);
    rs.print();

    cout << rs.getRandom() << endl;

    return 0;
}
