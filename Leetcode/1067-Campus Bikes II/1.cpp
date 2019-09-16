class Solution {
public:
    
    int distance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    int assignBikesAux(vector<vector<int>>& workers, vector<vector<int>>& bikes, int worker_index, int mask){
        if (worker_index == workers.size()) return 0;
        
        int min_distance = INT_MAX;
        for (int i = 0 ; i < bikes.size(); ++i){
            if (mask & (1 << i)) continue;
            
            min_distance = min(min_distance, distance(workers[worker_index], bikes[i]) + assignBikesAux(workers, bikes, worker_index + 1, mask | (1 << i)));
        }
        
        return min_distance;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
        return assignBikesAux(workers, bikes, 0, 0);
    }
};