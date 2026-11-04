#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

TreeNode* build(vector<int>& nums, int lo, int hi) {

    if (lo > hi)
        return nullptr;

    int mid = lo + (hi - lo) / 2;

    TreeNode* node = new TreeNode(nums[mid]);

    node->left = build(nums, lo, mid - 1);

    node->right = build(nums, mid + 1, hi);

    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size() - 1);
}

void levelOrder(TreeNode* root) {
    if (!root) {
        cout << "Empty Tree";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        cout << cur->val << " ";

        if (cur->left)
            q.push(cur->left);

        if (cur->right)
            q.push(cur->right);
    }
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    TreeNode* root = sortedArrayToBST(nums);

    cout << "Balanced BST Level Order: ";
    levelOrder(root);

    return 0;
}
