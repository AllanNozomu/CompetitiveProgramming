\*
Author: allannozomu
Runtime: 48 ms
Memory: 19.4 MB*\

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL){
            return NULL;
        } 
        if (t1 != NULL && t2 == NULL){
            TreeNode *new_node = new TreeNode(t1->val);
            new_node->left = t1->left;
            new_node->right = t1->right;
            return new_node;
        }
        if (t1 == NULL && t2 != NULL){
            TreeNode *new_node = new TreeNode(t2->val);
            new_node->left = t2->left;
            new_node->right = t2->right;
            return new_node;
        }
        TreeNode *new_node = new TreeNode(t1->val + t2->val);
        new_node->left = mergeTrees(t1->left, t2->left);
        new_node->right = mergeTrees(t1->right, t2->right);
        return new_node;
    }
};