#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > result;
    queue<pair<TreeNode*, int> > q;
    vector<int> current_level;
    int current_height = 0;

    if (root == NULL)
        return result;

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<TreeNode*, int> top_node = q.front();
        q.pop();

        if (current_height != top_node.second) {
            result.push_back(current_level);
            ++current_height;
            current_level.clear();
        }

        current_level.push_back(top_node.first->val);

        if (top_node.first->left != NULL)
            q.push(make_pair(top_node.first->left, top_node.second + 1));

        if (top_node.first->right != NULL)
            q.push(make_pair(top_node.first->right, top_node.second + 1));
    }

    result.push_back(current_level);

    return result;
}


int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int> > bfs_order = levelOrder(root);

    for (size_t i = 0; i < bfs_order.size(); ++i) {
        for (size_t j = 0; j < bfs_order[i].size(); ++j) {
            cout << bfs_order[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
