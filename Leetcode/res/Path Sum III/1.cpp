\*
Author: allannozomu
Runtime: 28 ms
Memory: 14.6 MB*\

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
    int countPath(TreeNode* root, int sum, int target){
        if (root == NULL){
            return 0;
        }
        int count = 0;
        if (sum + root->val == target){
            count++;
        }
        return count + countPath(root->left, sum+root->val, target) + countPath(root->right, sum+root->val, target);
    }
    
    int tranverse(TreeNode* root, int target){
        if (root == NULL) return 0;
        return countPath(root, 0, target) + 
            tranverse(root->left, target) + tranverse(root->right, target);
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        return tranverse(root, sum);
    }
};
