#include <iostream>
#include <vector>

using namespace std;


void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    int rt = n - k % n - 1;

    int l = 0;
    int r = rt;

    while (l < r)
        swap(nums[l++], nums[r--]);

    l = rt + 1;
    r = n - 1;

    while (l < r)
        swap(nums[l++], nums[r--]);

    l = 0;
    r = n - 1;

    while (l < r)
        swap(nums[l++], nums[r--]);
}


int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 8;

    rotate(nums, k);

    for (auto const &v: nums)
        cout << v << ' ';
    cout << endl;

    return 0;
}
