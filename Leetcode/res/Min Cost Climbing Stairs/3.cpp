\*
Author: allannozomu
Runtime: 4 ms
Memory: 9.2 MB*\

class Solution {
public:
    int minCostClimbingStairsAux(vector<int>& cost, int index, vector<int>& memo, vector<int>& visited){
        if (index >= cost.size()){
            return 0;
        }
        if (visited[index]){
            return memo[index];
        }
        visited[index] = 1;
        memo[index] = cost[index] + min(minCostClimbingStairsAux(cost, index + 1, memo, visited), minCostClimbingStairsAux(cost, index + 2, memo, visited));
        return memo[index];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo (cost.size());
        vector<int> visited(cost.size());
            
        return min(minCostClimbingStairsAux(cost, 0, memo, visited), minCostClimbingStairsAux(cost, 1, memo, visited));
    }
};