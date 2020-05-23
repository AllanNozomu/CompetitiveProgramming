\*
Author: allannozomu
Runtime: 368 ms
Memory: 99.3 MB*\

class Solution {
private:
    vector<unordered_map<int, int>> visited;
    vector<unordered_map<int, int>> dp;
    
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
        visited = vector<unordered_map<int, int>>(nums.size());
        dp = vector<unordered_map<int, int>>(nums.size());
        return DFS(nums, 0, S, 0);
    }
};