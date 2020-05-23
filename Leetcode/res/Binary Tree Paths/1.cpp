\*
Author: allannozomu
Runtime: 4 ms
Memory: 11.5 MB*\

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
    void binaryTreecPathsRec(TreeNode* root, vector<string>& paths, string path){
        if (root->left == NULL && root->right  == NULL){
            paths.push_back(path + to_string(root->val));
            return;
        }
        if (root->left != NULL)
            binaryTreecPathsRec(root->left, paths, path + to_string(root->val) + "->");
        if (root->right != NULL)
            binaryTreecPathsRec(root->right, paths, path + to_string(root->val) + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        binaryTreecPathsRec(root, res, "");
        return res;
    }
};