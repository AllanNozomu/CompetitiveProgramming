class Solution {
public:
    bool has_cycle(vector<vector<int>> & graph, vector<bool>& visited, vector<bool>& visited_all, int pos){
        if (visited[pos]) return true;
        
        visited[pos] = true;
        visited_all[pos] = true;
        
        bool res = false;
        for (int neighbour : graph[pos]){
            res |= has_cycle(graph, visited, visited_all, neighbour);
            if (res) return true;
        }
        visited[pos] = false;
        return res;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        unordered_set<int> non_root;
        
        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            non_root.insert(edge[0]);
        }
        
        vector<bool> visited_all = vector<bool> (numCourses, false);
        for (int i = 0; i < numCourses; ++i){
            if (non_root.find(i) == non_root.end()){
                cout << i << endl;
                vector<bool> visited = vector<bool> (numCourses, false);
                if (has_cycle(graph, visited, visited_all, i)) return false;
            }   
        }
        for (auto node : visited_all){
            if (!node) return false;
        }
        return true;
    }
};