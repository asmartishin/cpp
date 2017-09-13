#include <iostream>
#include <map>
#include <vector>
#include <set>


struct Solja {
    long long int height;
    long long int age;
    long long int index;

    Solja(const long long int height, const long long int age, const long long int index)
    : height(height)
    , age(age)
    , index(index)
    {}

    bool operator< (const Solja& other) const {
        return (
            height < other.height
            || height == other.height && age < other.age
            || height == other.height && age == other.age && index < other.index
        );
    }
};

void do_one_test() {
    long long int N;
    std::cin >> N;

    std::vector<long long int> heights(N);
    std::vector<long long int> heights_indices(N);
    for (size_t i = 0; i < N; ++i) {
        long long int index_of_height;
        std::cin >> index_of_height;
        heights[index_of_height - 1] = i;
        heights_indices[i] = index_of_height - 1;
    }

    std::map<long long int, long long int> queue_index_by_last_height;
    std::vector<std::vector<long long int> > queues;
    for (size_t i = 0; i < N; ++i) {
        long long int index_of_age;
        std::cin >> index_of_age;
        long long int height = heights[index_of_age - 1];
        auto it = queue_index_by_last_height.lower_bound(height);
        size_t target_index;
        if (it == queue_index_by_last_height.begin()) {
            queues.push_back(std::vector<long long int>());
            target_index = queues.size() - 1;
        } else {
            --it;
            target_index = it->second;
        }
        if (queues[target_index].size() > 0) {
            long long int last_element = queues[target_index][queues[target_index].size() - 1];
            queue_index_by_last_height.erase(last_element);
        }
        queues[target_index].push_back(height);
        queue_index_by_last_height[height] = target_index;
    }

    std::cout << queues.size() << std::endl;
    for (size_t i = 0; i < queues.size(); ++i) {
        std::cout << queues[i].size() << " ";
        for (size_t j = 0; j < queues[i].size(); ++j) {
            std::cout << heights_indices[queues[i][j]] + 1;
            if (j + 1 < queues[i].size()) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    long long int T;
    std::cin >> T;
    for (size_t i = 0; i < T; ++i) {
        do_one_test();
    }
    return 0;
}

