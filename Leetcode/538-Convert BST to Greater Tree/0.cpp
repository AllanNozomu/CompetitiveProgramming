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
    void convert(TreeNode* curr, int* sum){
        if (curr == NULL){
            return;
        }
        convert(curr->right, sum);
        int new_val = curr->val + *sum;
        *sum += curr->val;
        curr->val = new_val;
        convert(curr->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, &sum);
        return root;
    }
};