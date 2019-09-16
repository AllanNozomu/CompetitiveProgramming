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
    int robHelper(TreeNode* curr, bool parent_taken, unordered_map<TreeNode*, int> memo[]){
        if (curr == NULL){
            return 0;
        }
        if (memo[parent_taken == 0 ? 1 : 0][curr] > 0){
            return memo[parent_taken == 0 ? 1 : 0][curr];
        }
        
        int res_taken = 0;
        if (parent_taken == false){
            res_taken = curr->val + 
                robHelper(curr->left, true, memo) +
                robHelper(curr->right, true, memo);
        }
        int res_not_taken = robHelper(curr->left, false, memo) +
                robHelper(curr->right, false, memo); 
        
        memo[parent_taken == 0 ? 1 : 0][curr] = max(res_taken, res_not_taken);
        return memo[parent_taken == 0 ? 1 : 0][curr];
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo[2];
        
        return robHelper(root, false, memo);
    }
};