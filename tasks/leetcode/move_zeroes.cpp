#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> nums{4,2,4,0,0,3,0,5,1,0};

    int l = 0, r = 0;

    while (r < nums.size()) {
        if (nums[l] == 0) {
            while (r < nums.size() - 1 && nums[r] == 0)
                ++r;

            if (nums[r] != 0)
                swap(nums[l], nums[r]);
        }
        ++l;
        ++r;
    }

    for (auto const& v: nums)
        cout << v << endl;

    return 0;
}
