/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root->val == p->val || root->val == q->val) return root;

        TreeNode* lNode = lowestCommonAncestor(root->left , p ,q);
        TreeNode* rNode = lowestCommonAncestor(root->right , p ,q);

        if(lNode == nullptr) return rNode;
        else if(rNode == nullptr) return lNode;
        else return root;
    }
};
