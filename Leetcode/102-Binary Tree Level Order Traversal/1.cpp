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
vector<vector<int>> levelOrder(TreeNode * root){
  vector<vector<int>> result;
  queue<pair<TreeNode*, int> > nodes;
  
  if (root == NULL){
    return result;
  }
  
  nodes.push({root, 0});
  
  while(!nodes.empty()){
    pair<TreeNode*, int> curr = nodes.front();
    TreeNode* curr_node = curr.first;
    int curr_level = curr.second;
    nodes.pop();
    
    if (curr_level == result.size()){
      result.push_back(vector<int>());
    }
    result[curr_level].push_back(curr_node->val);
    
    if (curr_node->left != NULL){
      nodes.push({curr_node->left, curr_level + 1});
    }
    if (curr_node->right != NULL){
      nodes.push({curr_node->right, curr_level + 1});
    }
  }
  return result;
}
  
  

};