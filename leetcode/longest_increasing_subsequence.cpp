#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int lengthOfLIS(vector<int> &nums) {
    size_t n = nums.size();
    if (n == 0)
        return 0;

    vector<int> states(n, 1);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (nums[i] > nums[j])
                states[i] = max(states[i], states[j] + 1);
        }
    }

    return *max_element(states.begin(), states.end());
}


int main() {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}
