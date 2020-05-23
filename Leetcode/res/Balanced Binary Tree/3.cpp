\*
Author: allannozomu
Runtime: 12 ms
Memory: 20.1 MB*\

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
    pair<bool, int> isBalancedHelper(TreeNode* root) {
        if (!root) return {true, 0};
        
        auto left = isBalancedHelper(root->left);
        auto right = isBalancedHelper(root->right);
        
        if (abs(left.second - right.second) <= 1){
            return {left.first & right.first, max(left.second, right.second) + 1};
        }
        return {false, -1};
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;
    }
};