#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    vector<int> nums{1,2,1,1,1};
    sort(nums.begin(), nums.end());

    cout << nums[nums.size() / 2] << endl;

    return 0;
}
