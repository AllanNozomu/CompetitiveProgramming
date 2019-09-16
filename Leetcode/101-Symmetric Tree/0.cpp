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
    bool is_simetric(TreeNode* left, TreeNode* right){
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if (left->val != right->val)
            return false;
        return is_simetric(left->left, right->right) && is_simetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return is_simetric(root->left, root->right);
    }
};