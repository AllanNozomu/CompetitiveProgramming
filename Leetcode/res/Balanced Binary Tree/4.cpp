\*
Author: allannozomu
Runtime: 8 ms
Memory: 17.5 MB*\

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
    int treeDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        return max(treeDepth(root->left) + 1, treeDepth(root->right) + 1);
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        
        if (abs(left - right) <= 1){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }
};