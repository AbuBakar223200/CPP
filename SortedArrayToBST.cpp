//Convert Sorted Array to Binary Search Tree
#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBSTHelper(const vector<int>& nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    node->right = sortedArrayToBSTHelper(nums, mid + 1, right);

    return node;
}

TreeNode* sortedArrayToBST(const vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}

// Utility function to print the tree in a pre-order manner
void preOrder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);

    cout << "Pre-order traversal of the constructed BST: ";
    preOrder(root);
    cout << endl;

    return 0;
}
