#include <iostream>
#include <vector>
#include <unordered_set>

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


int main() {
    vector<int> nums{1, 2, 3};

    auto permutations = permute(nums);

    for (size_t i = 0; i < permutations.size(); ++i) {
        for (size_t j = 0; j < permutations[i].size(); ++j)
            cout << permutations[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
