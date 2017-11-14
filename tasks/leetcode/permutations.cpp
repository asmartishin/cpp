#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

using namespace std;


void permuteHelper(int v, vector<int> current_permutation, unordered_set<int> available_numbers, vector<vector<int> > &result) {
    current_permutation.push_back(v);
    available_numbers.erase(v);

    if (available_numbers.size() == 0)
        result.push_back(current_permutation);

    for (auto const &v: available_numbers)
        permuteHelper(v, current_permutation, available_numbers, result);
}


vector<vector<int> > permute(vector<int> &nums) {
    vector<vector<int> > result;
    unordered_set<int> available_numbers(nums.begin(), nums.end());

    for (auto const &v: nums)
        permuteHelper(v, vector<int>{}, available_numbers, result);

    return result;
}


void print_permutations(vector<int> &nums, int l, int r) {
    if (l == r) {
        for (auto const& v: nums) {
            cout << v << ' ';
        }
        cout << endl;
    } else {
        for (size_t i = l; i <= r; ++i) {
            swap(nums[l], nums[i]);
            print_permutations(nums, l + 1, r);
            swap(nums[l], nums[i]);
        }
    }
}


bool next_permutation(vector<int> &nums) {
    int l = nums.size() - 1;
    int r = nums.size() - 1;

    while (l > 0 && nums[l - 1] >= nums[l])
        --l;

    if (l <= 0)
        return false;

    int p = l - 1;

    while (nums[r] < nums[p])
        --r;

    swap(nums[p], nums[r]);

    r = nums.size() - 1;
    while (l < r) {
        swap(nums[l++], nums[r--]);
    }

    return true;
}


int main() {
    vector<int> nums{1, 2, 3};

    do {
        for (auto const &v: nums)
            cout << v << ' ';
        cout << endl;
    } while (next_permutation(nums));

//    print_permutations(nums, 0, nums.size() - 1);

//    auto permutations = permute(nums);

//    for (size_t i = 0; i < permutations.size(); ++i) {
//        for (size_t j = 0; j < permutations[i].size(); ++j)
//            cout << permutations[i][j] << ' ';
//        cout << endl;
//    }

    return 0;
}
