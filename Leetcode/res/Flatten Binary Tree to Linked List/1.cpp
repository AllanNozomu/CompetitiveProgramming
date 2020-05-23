\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.7 MB*\

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

    void flatten(TreeNode* root) {
        if (root == NULL) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* new_left = root->left;
        TreeNode* new_left_head;
        if (new_left == NULL){
            new_left = root->right;
            new_left_head = new_left;
        } else {
            new_left_head = new_left;
            while(new_left->right != NULL){
                new_left = new_left->right;
            }
            new_left->right = root->right;
        }
        
        root->right = new_left_head;
        root->left = NULL;
    }
};