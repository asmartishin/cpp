#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
}


int main() {
    vector<int> nums1(6);
    nums1[0] = 1;
    nums1[1] = 3;
    nums1[2] = 6;

    vector<int> nums2{1, 2, 7};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    for (auto const &v: nums1)
        cout << v << ' ';
    cout << endl;

    return 0;
}
