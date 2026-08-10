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
    pair<int,TreeNode*> solve(TreeNode * root ){
        if (root == nullptr) return {-1,root};
        if (root->left == nullptr && root->right == nullptr) return {0,root};

        auto left = solve(root->left);
        auto right = solve(root->right);


        if(left.first>right.first) return {left.first + 1,left.second} ;
        else if(left.first<right.first) return {right.first + 1,right.second} ;
        else return {left.first+1,root};
    } 
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int,TreeNode*> p = solve(root);
        return p.second;
    }

};
