// https://leetcode.com/problems/path-sum-ii/submissions/2141350272/

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
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& output, vector<int>& tempArr){
        if(!root)
            return;
        tempArr.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum)
            output.push_back(tempArr);
        else{
            targetSum-= root->val;
            dfs(root->left, targetSum, output, tempArr);
            dfs(root->right, targetSum, output, tempArr);
        }
        tempArr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> output;
        vector<int> tempArr;
        dfs(root,targetSum,output,tempArr);
        return output;
    }
};
