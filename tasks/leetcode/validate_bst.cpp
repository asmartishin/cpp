#include <iostream>
#include <limits>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};


bool isValidBSTHelper(TreeNode *root, long long min_value, long long max_value);


bool isValidBST(TreeNode *root) {
    return isValidBSTHelper(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}


bool isValidBSTHelper(TreeNode *root, long long min_value, long long max_value) {
    if (root == NULL)
        return true;

    if (root->val <= min_value || root->val >= max_value)
        return false;

    return isValidBSTHelper(root->left, min_value, root->val)
        && isValidBSTHelper(root->right, root->val, max_value);
}


int main() {
    TreeNode *root = new TreeNode(0);

    cout << isValidBST(root) << endl;

    return 0;
}
