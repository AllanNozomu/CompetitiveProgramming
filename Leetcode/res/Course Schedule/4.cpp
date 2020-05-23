\*
Author: allannozomu
Runtime: 28 ms
Memory: 14.8 MB*\

class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        unordered_map<int, int> prerequisites_count;
        unordered_set<int> visited;
        
        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            prerequisites_count[edge[0]]++;
        }
        
        queue <int> zero_prerequisites;
        for (int node = 0 ; node < numCourses; ++node) {
            if (prerequisites_count[node] == 0) zero_prerequisites.push(node);
        }
        
        while(!zero_prerequisites.empty()){
            int curr = zero_prerequisites.front();
            zero_prerequisites.pop();
            visited.insert(curr);
            
            for (int neig : graph[curr]){
                if (--prerequisites_count[neig] == 0){
                    zero_prerequisites.push(neig);
                }
            }
        }
        
        if (visited.size() == numCourses) return true;
        return false;
        

    }
};