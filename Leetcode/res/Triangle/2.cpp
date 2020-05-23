\*
Author: allannozomu
Runtime: 8 ms
Memory: 10.6 MB*\

class Solution {
public:
    int minTotalAux(vector<vector<int>>& triangle, int level, int index, vector<vector<int>>& visited, vector<vector<int>>& memo){
        if (level == triangle.size() - 1){
            return triangle[level,index];
        }
        if (visited[level,index])
            return memo[level,index];
        
        visited[level,index] = 1;
        memo[level,index] = triangle[level,index];
        memo[level,index] += min(minTotalAux(triangle, level + 1, index, visited, memo), 
                                 minTotalAux(triangle, level + 1, index + 1, visited, memo));
        return memo[level,index];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> visited (triangle.size(), vector<int>(triangle.size()));
        vector<vector<int>> memo (triangle.size(), vector<int>(triangle.size()));
        
        return minTotalAux(triangle, 0, 0, visited, memo);
    }
};