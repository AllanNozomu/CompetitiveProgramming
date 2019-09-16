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
private:
    int maximal;
    
public:
    int maxPathSumAux(TreeNode* root){
        if (root->left == NULL && root->right == NULL) return root->val;
        if (root->left && root->right){
            int left_rec = maxPathSumAux(root->left);
            int right_rec = maxPathSumAux(root->right);
            maximal = max({maximal, left_rec, right_rec, left_rec + right_rec + root->val, root->val});
            return max({left_rec + root->val, right_rec + root->val, root->val});
        }
        if (root->left){
            int left_rec = maxPathSumAux(root->left);
            maximal = max({maximal, left_rec, left_rec + root->val, root->val});
            return max(left_rec + root->val, root->val);
        }
        int right_rec = maxPathSumAux(root->right);
        maximal = max({maximal, right_rec, right_rec + root->val, root->val});
        return max(right_rec + root->val, root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        
        maximal = root->val;
        int res = maxPathSumAux(root);
        return max(res, maximal);
    }
};