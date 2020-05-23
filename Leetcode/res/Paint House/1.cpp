\*
Author: allannozomu
Runtime: 8 ms
Memory: 10.2 MB*\

class Solution {
public:
    int visit(vector<vector<int>>& costs, int level, int visited, vector<vector<int>>& memo){
        if (level == costs.size()) return 0;
        
        if (memo[level,visited]) return memo[level,visited];
        
        int res = INT_MAX;
        for (int i = 0 ; i < 3; ++i){
            if (i != visited)
                res = min(res, costs[level,i] + visit(costs, level + 1, i, memo));
        }
        memo[level,visited] = res;
        return res;
    }
    
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> memo (costs.size(), vector<int>(3));
        return min({visit(costs, 0, 0, memo), visit(costs, 0, 1, memo), visit(costs, 0, 2, memo)});
    }
};