\*
Author: allannozomu
Runtime: 8 ms
Memory: 10 MB*\

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
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return {};
        
        unordered_map<int, vector<int>> mapa;
        vector<vector<int>> res;
        int minLevel = 0, maxLevel = 0;
        
        queue<pair<int,TreeNode*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int level = front.first;
            TreeNode* curr = front.second;
            
            minLevel = min(minLevel, level);
            maxLevel = max(maxLevel, level);
            
            mapa[level].push_back(curr->val);
            if (curr->left) 
                q.push({level - 1, curr->left});
            if (curr->right) 
                q.push({level + 1, curr->right});
        }
        
        for (int i = minLevel; i <= maxLevel; ++i){
            res.push_back(mapa[i]);
        }
        return res;
    }
};