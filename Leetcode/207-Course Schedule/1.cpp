class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        vector<int> pre_req_count = vector<int>(numCourses);
        unordered_set<int> non_root;
        
        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            pre_req_count[edge[0]]++;
            non_root.insert(edge[0]);
        }
        
        queue<int> independent;
        int removed = 0;
        for (int i = 0 ; i < numCourses; ++i){
            if (non_root.find(i) == non_root.end()){
                independent.push(i);
                removed ++;
            }
        }
        
        while(!independent.empty()){
            int curr = independent.front();
            independent.pop();
            
            for (int neigh : graph[curr]){
                pre_req_count[neigh]--;
                if (pre_req_count[neigh] == 0){
                    independent.push(neigh);
                    removed++;
                }
            }
        }
        
        return removed == numCourses;
    }
};