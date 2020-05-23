\*
Author: allannozomu
Runtime: 360 ms
Memory: 39.9 MB*\

class Solution {
public:

    int distance(vector<int>& worker, vector<int>& bike){
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    // int cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    //     if (get<0>(a) == get<0>(b)){
    //         if (get<1>(a) == get<1>(b)) {
    //             return get<2>(a) < get<2>(b);
    //         }
    //         return get<1>(a) < get<1>(b);
    //     } 
    //     return get<0>(a) < get<0>(b);
    // }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<tuple<int, int, int>> bikes_workers;
        
        for (int worker_index = 0; worker_index < workers.size(); ++worker_index){
            for (int bike_index = 0; bike_index < bikes.size(); ++bike_index){
                
                bikes_workers.push_back({
                    distance(workers[worker_index], bikes[bike_index]),
                    bike_index,
                    worker_index
                });
            }
        }
        sort(bikes_workers.begin(), bikes_workers.end());
        
        vector<int> workers_res(workers.size(), -1);
        vector<int> visited_bikes(bikes.size());
        
        for (tuple<int, int, int> bike_worker : bikes_workers){
            if (visited_bikes[get<1>(bike_worker)] == 0 && workers_res[get<2>(bike_worker)] == -1){
                visited_bikes[get<1>(bike_worker)] = 1;
                workers_res[get<2>(bike_worker)] = get<1>(bike_worker);
            }
        }
        return workers_res;
    }
};