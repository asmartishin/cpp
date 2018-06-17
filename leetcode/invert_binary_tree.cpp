#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


void inorder(TreeNode *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}


void invertTree(TreeNode *root) {
    if (root == NULL)
        return;

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    invertTree(root);

    inorder(root);
    cout << endl;

    return 0;
}
