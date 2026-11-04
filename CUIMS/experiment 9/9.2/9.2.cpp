#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

TreeNode* build(vector<int>& pre, int preL, int preR,
                vector<int>& in, int inL, int inR,
                unordered_map<int, int>& idx) {

    if (preL > preR)
        return nullptr;

    int rootValue = pre[preL];

    int mid = idx[rootValue];

    int leftSize = mid - inL;

    TreeNode* root = new TreeNode(rootValue);

    root->left = build(pre,
                       preL + 1,
                       preL + leftSize,
                       in,
                       inL,
                       mid - 1,
                       idx);

    root->right = build(pre,
                        preL + leftSize + 1,
                        preR,
                        in,
                        mid + 1,
                        inR,
                        idx);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    unordered_map<int, int> idx;

    for (int i = 0; i < inorder.size(); i++) {
        idx[inorder[i]] = i;
    }

    return build(preorder, 0, preorder.size() - 1,
                 inorder, 0, inorder.size() - 1, idx);
}

void printTree(TreeNode* root) {

    if (!root) {
        cout << "Empty tree";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Level order traversal: ";
    printTree(root);

    return 0;
}
