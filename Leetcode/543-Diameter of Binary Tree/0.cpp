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
    
    pair<int, int> helper(TreeNode* root) {
        if (root == NULL){
            return {0,0};
        }
        pair<int, int> left_res = helper(root->left);
        pair<int, int> right_res = helper(root->right);
        
        int diameter = left_res.second + right_res.second;
        int height = max(left_res.second, right_res.second) + 1;
        
        return {max({diameter, left_res.first, right_res.first}), height};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).first;
    }
};