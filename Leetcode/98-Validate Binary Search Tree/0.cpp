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
    
    tuple<bool, int, int> isValidBSTAux(TreeNode* root){
        pair<int, int> res_left, res_right;
        if (root->left){
            if (root->right){
                auto res_left = isValidBSTAux(root->left);
                auto res_right = isValidBSTAux(root->right);
                return { 
                    get<0>(res_left) & get<0>(res_right) & root->val > get<2>(res_left) & root->val < get<1>(res_right),
                    get<1>(res_left),
                    get<2>(res_right)
                };
            } else {
                auto res_left = isValidBSTAux(root->left);
                return { 
                    get<0>(res_left) & root->val > get<2>(res_left),
                    get<1>(res_left),
                    root->val 
                };
            }
        } else {
            if (root->right){
                auto res_right = isValidBSTAux(root->right);
                return { 
                    get<0>(res_right) & root->val < get<1>(res_right),
                    root->val,
                    get<2>(res_right) 
                };
            } else {
                return {true, root->val, root->val};
            }
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if (root==NULL) return true;
        return get<0>(isValidBSTAux(root));
    }
};