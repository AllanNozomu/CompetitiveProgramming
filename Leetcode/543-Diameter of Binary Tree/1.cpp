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
    int heightTree(TreeNode* node){
        if (node == NULL){
            return 0;
        }
        return max(heightTree(node->left), heightTree(node->right)) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int diameter = heightTree(root->left) + heightTree(root->right);
        return max({diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right), diameter});
    }
};