#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


class Solution {
public:
    int get_shift(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;

            if (nums[m] > nums[r])
                l = m + 1;
            else
                r = m;
        }

        return r;
    }

    int search(vector<int> &nums, int target) {
        auto shift = get_shift(nums);

        int size = nums.size();

        int l = 0;
        int r = nums.size();

        while (l < r) {
            int m = (l + r) / 2;
            auto mShifted = m + shift;

            if (mShifted >= size)
                mShifted = mShifted - size;

            if (nums[mShifted] == target)
                return mShifted;
            else if (nums[mShifted] > target)
                r = m;
            else
                l = m + 1;
        }

        return -1;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for (size_t i = 0; i < n; ++i)
        cin >> nums[i];

    cout << Solution().search(nums, target) << endl;

    return 0;
}
