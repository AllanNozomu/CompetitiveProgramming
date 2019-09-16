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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        
        TreeNode* new_left = invertTree(root->right);
        TreeNode* new_right = invertTree(root->left);
        
        root->left = new_left;
        root->right = new_right;
        
        return root;
    }
};