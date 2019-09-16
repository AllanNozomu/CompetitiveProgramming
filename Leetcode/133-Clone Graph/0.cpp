/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        
        unordered_map<Node*, Node*> visited_nodes;
        
        queue<pair<Node*, Node*>> next_nodes;
        
        Node* new_head = new Node(node->val);
        next_nodes.push({new_head, node});
        visited_nodes[node] = new_head;
        
        while(!next_nodes.empty()){
            pair<Node*, Node*> curr_node = next_nodes.front();
            next_nodes.pop();
            
            for (Node* neighbor : curr_node.second->neighbors){
                auto find_node = visited_nodes.find(neighbor);
                if (find_node == visited_nodes.end()){
                    Node* new_node = new Node(neighbor->val);
                    // new_node->neighbors.push_back(curr_node.first);
                    curr_node.first->neighbors.push_back(new_node);
                    visited_nodes[neighbor] = new_node;
                    
                    next_nodes.push({new_node, neighbor});
                } else {
                    // find_node->second->neighbors.push_back(curr_node.first);
                    curr_node.first->neighbors.push_back(find_node->second);
                }
            }
        }
        return new_head;
    }
};