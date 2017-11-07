#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(-1), left(nullptr), right(nullptr) {}
};


int max_depth(TreeNode *root, int height = 0) {
    if (root == nullptr)
        return 0;

    ++height;

    if (root->left == nullptr && root->right == nullptr)
        return height;
    else {
        int l_height = numeric_limits<int>::min();
        int r_height = numeric_limits<int>::min();

        if (root->left != nullptr)
            l_height = max_depth(root->left, height);
        if (root->right != nullptr)
            r_height = max_depth(root->right, height);

        return max(r_height, l_height);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<TreeNode> tree(n);

    for (size_t i = 0; i < n; ++i) {
        int val, left, right;
        cin >> val >> left >> right;
        tree[i].val = val;
        tree[i].left = (left != -1) ? &tree[left] : nullptr;
        tree[i].right =  (right != -1) ? &tree[right]: nullptr;
    }

    cout << max_depth(&tree[0]) << endl;

    return 0;
}
