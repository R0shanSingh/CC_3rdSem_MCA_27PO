// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/2141409723/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
    Info dfs(TreeNode* root) {
        if (root == nullptr) {
            return {true, INT_MAX, INT_MIN, 0};
        }
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        if (left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal) {
            int currentSum = left.sum + root->val + right.sum;
            ans = max(ans, currentSum);
            return {true,min(left.minVal, root->val),max(right.maxVal, root->val),currentSum};
        }
        return {false, 0, 0, 0};
    }
};
