\*
Author: allannozomu
Runtime: 4 ms
Memory: 9.5 MB*\

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
    void righSideViewAux(TreeNode* root, int level, vector<int>& values) {
        if (root == NULL) return;
        if (values.size() < level ) return;
        
        if (values.size() == level)
            values.push_back(root->val);
        
        righSideViewAux(root->right, level + 1, values);
        righSideViewAux(root->left, level + 1, values);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> values;
        righSideViewAux(root, 0, values);
        
        return values;
    }
};