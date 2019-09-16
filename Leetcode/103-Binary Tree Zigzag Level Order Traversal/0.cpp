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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        
        vector<vector<int>> zigzagorder;
        stack<pair<TreeNode*, int>> nodes_stack;
        stack<pair<TreeNode*, int>> new_nodes_stack;
        
        new_nodes_stack.push({root, 0});
        
        while(!new_nodes_stack.empty()){
            nodes_stack = move(new_nodes_stack);
            new_nodes_stack = stack<pair<TreeNode*, int>>();
            
            while(!nodes_stack.empty()){
                TreeNode* curr_node = nodes_stack.top().first;
                int level = nodes_stack.top().second;
                nodes_stack.pop();

                if (level == zigzagorder.size()){
                    zigzagorder.push_back({});
                }
                zigzagorder[level].push_back(curr_node->val);

                if (level % 2){
                    if (curr_node->right) new_nodes_stack.push({curr_node->right, level + 1});
                    if (curr_node->left) new_nodes_stack.push({curr_node->left, level + 1});
                } else {
                    if (curr_node->left) new_nodes_stack.push({curr_node->left, level + 1});
                    if (curr_node->right) new_nodes_stack.push({curr_node->right, level + 1});
                }
            }
        }
        
        return zigzagorder;
    }
};