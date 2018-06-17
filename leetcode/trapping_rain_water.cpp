#include <iostream>
#include <vector>

using namespace std;


int trap(vector<int> &height) {
    int l = 0;
    int r = height.size() - 1;
    int left_max = 0;
    int right_max = 0;
    int sum = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] >= left_max)
                left_max = height[l];
            else
                sum += left_max - height[l];
            ++l;
        } else {
            if (height[r] >= right_max)
                right_max = height[r];
            else
                sum += right_max - height[r];
            --r;
        }
    }

    return sum;
}


int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;

    return 0;
}
