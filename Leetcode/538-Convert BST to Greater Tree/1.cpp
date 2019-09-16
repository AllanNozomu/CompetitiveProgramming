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
    int sum = 0;
    
    void convert(TreeNode* curr){
        if (curr == NULL){
            return;
        }
        convert(curr->right);
        int new_val = curr->val + sum;
        sum += curr->val;
        curr->val = new_val;
        convert(curr->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }
};