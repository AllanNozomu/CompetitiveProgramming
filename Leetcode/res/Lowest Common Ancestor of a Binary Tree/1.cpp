\*
Author: allannozomu
Runtime: 24 ms
Memory: 23 MB*\

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
    void find_parents(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, TreeNode*> &parents){
        if (root == NULL) return;
        
        parents[root] = prev;
        find_parents(root->left, root, parents);
        find_parents(root->right, root, parents);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parents;
        find_parents(root, NULL, parents);
        
        vector<TreeNode*> p_vec, q_vec;
        
        while(p != NULL){
            p_vec.push_back(p);
            p = parents[p];
        }
        while(q != NULL){
            q_vec.push_back(q);
            q = parents[q];
        }
        TreeNode* LCA;
        auto p_pointer = p_vec.rbegin();
        auto q_pointer = q_vec.rbegin();
        while(p_pointer != p_vec.rend() && q_pointer != q_vec.rend() && *p_pointer == *q_pointer){
            LCA = *p_pointer;
            p_pointer++;
            q_pointer++;
        }
        return LCA;
        
    }
};