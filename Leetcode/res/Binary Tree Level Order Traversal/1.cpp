\*
Author: allannozomu
Runtime: 8 ms
Memory: 13.7 MB*\

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        vector<vector<int>> res;
        
        q.push({0,root});
        
        while(!q.empty()){
            int level = q.front().first;
            TreeNode* curr_node = q.front().second;
            q.pop();
            
            if (curr_node != NULL){

                if (res.size() == level){
                    res.push_back({});
                }
                res[level].push_back(curr_node->val);

                q.push({level + 1, curr_node->left});
                q.push({level + 1, curr_node->right});
            }
        }
        return res;
    }
};