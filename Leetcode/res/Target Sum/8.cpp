\*
Author: allannozomu
Runtime: 380 ms
Memory: 99.7 MB*\

class Solution {
private:
    unordered_map<int, unordered_map<int, int>> visited;
    unordered_map<int, unordered_map<int, int>> dp;
    
public:
    int DFS(vector<int>& nums, int level, int target, int sum){
        if (level == nums.size()){
            if (sum == target) return 1;
            return 0;
        }
        
        if (visited[level,sum]) 
            return dp[level,sum];

        int plus = DFS(nums, level+1, target, sum + nums[level]);
        int minus = DFS(nums, level+1, target, sum - nums[level]);
        
        visited[level,sum] = 1;
        dp[level,sum] = plus + minus;
        return dp[level,sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return DFS(nums, 0, S, 0);
    }
};