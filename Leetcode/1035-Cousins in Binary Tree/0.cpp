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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y){
            return false;
        }
        
        TreeNode* parent_x = NULL;
        TreeNode* parent_y = NULL;
        int level_x = NULL;
        int level_y = NULL;
        
        queue<tuple<int, TreeNode*, TreeNode*>> level_curr_parent;
        if (root->left){
            level_curr_parent.push({0, root->left, root});
        }
        if (root->right){
            level_curr_parent.push({0, root->right, root});
        }
        
        while(!level_curr_parent.empty()){
            auto curr = level_curr_parent.front();
            level_curr_parent.pop();
            
            if (get<1>(curr)->val == x){
                parent_x = get<2>(curr);
                level_x = get<0>(curr);
            } else if (get<1>(curr)->val == y){
                parent_y = get<2>(curr);
                level_y = get<0>(curr);
            }
            if (parent_x && parent_y){
                return parent_x->val != parent_y->val && level_x == level_y;
            }
            if (get<1>(curr)->left)
                level_curr_parent.push({get<0>(curr) + 1, get<1>(curr)->left, get<1>(curr)});
            if (get<1>(curr)->right)
                level_curr_parent.push({get<0>(curr) + 1, get<1>(curr)->right, get<1>(curr)});
        }
        
        return false;
    }
};