/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    pair<Node*, Node*> aux(Node* root) {
        if (root->left == NULL && root->right == NULL){
            root->left = root->right = root;
            return {root, root};
        }
        
        if (root->left){
            auto leftList = aux(root->left);
            if (root->right){
                auto rightList = aux(root->right);
                root->left = leftList.second;
                root->left->right = root;
                root->right = rightList.first;
                root->right->left = root;
                
                leftList.first->left = rightList.second;
                rightList.second->right = leftList.first;
                return {leftList.first, rightList.second};
            } else {
                root->left = leftList.second;
                root->left->right = root;
                root->right = leftList.first;
                root->right->left = root;
                
                return {leftList.first, root};
            }
        }
        auto rightList = aux(root->right);

        root->right = rightList.first;
        root->right->left = root;
        root->left = rightList.second;
        root->left->right = root;

        return {root, rightList.second};
    }
    
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return root;
        
        return aux(root).first;
    }
};