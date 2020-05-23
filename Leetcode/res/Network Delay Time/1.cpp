\*
Author: allannozomu
Runtime: 112 ms
Memory: 32.2 MB*\

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if (N == 0) return N;
        
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for(vector<int> time : times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        priority_queue<pair<int, int>> next_nodes;
        vector<int> visited(N + 1, -1);
        int visited_number = 0;
        int last_time = 0;
        
        next_nodes.push({0, K});
        
        while(!next_nodes.empty() && visited_number != N){
            pair<int, int> curr = next_nodes.top();
            next_nodes.pop();
            
            curr.first *= -1;
            if (visited[curr.second] != -1) continue;
            
            visited[curr.second] = curr.first;
            visited_number++;
            last_time = curr.first;
            
            for (pair<int, int> neighbor : graph[curr.second]){
                if (visited[neighbor.first] == -1){
                    next_nodes.push({-(curr.first + neighbor.second), neighbor.first});
                }
            }
        }
        if (visited_number == N) return last_time;
        return -1;
    }
};