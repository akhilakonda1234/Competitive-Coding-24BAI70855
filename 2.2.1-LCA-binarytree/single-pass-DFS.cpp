#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Find path from root to target
bool findPath(TreeNode* root, int target,
              vector<TreeNode*>& path) {

    if (root == NULL)
        return false;

    path.push_back(root);

    if (root->val == target)
        return true;

    if (findPath(root->left, target, path) ||
        findPath(root->right, target, path))
        return true;

    path.pop_back();
    return false;
}

// Brute Force LCA
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {

    vector<TreeNode*> path1;
    vector<TreeNode*> path2;

    findPath(root, p, path1);
    findPath(root, q, path2);

    int i = 0;

    while (i < path1.size() &&
           i < path2.size() &&
           path1[i] == path2[i]) {
        i++;
    }

    return path1[i - 1];
}

// Build tree from level order
TreeNode* buildTree(vector<int>& values) {

    if (values.empty())
        return NULL;

    TreeNode* root = new TreeNode(values[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < values.size()) {

        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> values(n);

    cout << "Enter node values in level order (-1 for NULL):\n";

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int p, q;

    cout << "Enter p and q: ";
    cin >> p >> q;

    TreeNode* root = buildTree(values);

    TreeNode* answer = lowestCommonAncestor(root, p, q);

    cout << "LCA = " << answer->val << endl;

    return 0;
}
