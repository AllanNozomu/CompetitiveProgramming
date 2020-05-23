\*
Author: allannozomu
Runtime: 16 ms
Memory: 20.4 MB*\

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
    double abs_diff(int v, double target){
        return abs(v - target);
    }
    
    int closestValueAux(TreeNode* curr, double target){
        if (target < curr->val) {
            if (curr->left != NULL){
                int res_left = closestValueAux(curr->left, target);
                if (abs_diff(curr->val, target) > abs_diff(res_left, target)){
                    return res_left;
                }
            }
        } else {
            if (curr->right != NULL){
                int res_right = closestValueAux(curr->right, target);
                if (abs_diff(curr->val, target) > abs_diff(res_right, target)){
                    return res_right;
                }
            }
        }
        return curr->val;
    }
    
    int closestValue(TreeNode* root, double target) {
        return closestValueAux(root, target);
    }
};