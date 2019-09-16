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
    pair<bool, pair<int, int>> validBSTAux(TreeNode* root){
        if (!root->left && !root->right) return {true, {root->val, root->val}};
        
        if (root->left && root->right){
            auto l_res = validBSTAux(root->left);
            auto r_res = validBSTAux(root->right);

            if (l_res.first && r_res.first){
                auto l_values = l_res.second;
                auto r_values = r_res.second;

                if (l_values.second < root->val && r_values.first > root->val){
                    return {true, {l_values.first, r_values.second}};
                }
            }
        } else if (root->left){
            auto l_res = validBSTAux(root->left);
            if (l_res.first && l_res.second.second < root->val){
                return {true, {l_res.second.first, root->val}};
            }
        } else{
            auto r_res = validBSTAux(root->right);
            if (r_res.first && r_res.second.first > root->val){
                return {true, {root->val, r_res.second.second}};
            }
        }
        return {false, {-1,-1}};
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return validBSTAux(root).first;
    }
};