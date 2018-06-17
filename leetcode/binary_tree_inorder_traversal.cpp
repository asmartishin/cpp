#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


void inorderTraversalHelper(TreeNode *root, vector<int> &traversal) {
    if (root->left != NULL)
        inorderTraversalHelper(root->left, traversal);
    traversal.push_back(root->val);
    if (root->right != NULL)
        inorderTraversalHelper(root->right, traversal);
}


vector <int> inorderTraversal(TreeNode *root) {
    vector<int> traversal;

    if (root = NULL)
        return traversal;

    inorderTraversalHelper(root, traversal);

    return traversal;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left = new TreeNode(4);
    root->right->left = new TreeNode(3);

    vector<int> traversal = inorderTraversal(root);

    for (auto const &v: traversal)
        cout << v << ' ';
    cout << endl;

    return 0;
}
