\*
Author: allannozomu
Runtime: 20 ms
Memory: 11.4 MB*\

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors = vector<int>(graph.size());
    
        for(int node = 0; node < graph.size(); ++node){
            if (colors[node]) {
                continue;
            }
            queue<pair<int, int>> nodes_queue;
            colors[node] = 1;
            
            nodes_queue.push({node, 1});
            while(!nodes_queue.empty()){
                pair<int, int> curr_node = nodes_queue.front();
                nodes_queue.pop();
                
                for (int neigh : graph[curr_node.first]){
                    if (colors[neigh] == 0){
                        colors[neigh] = -curr_node.second;
                        nodes_queue.push({neigh, -curr_node.second});
                    } else if (colors[neigh] != -curr_node.second){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};