\*
Author: allannozomu
Runtime: 1108 ms
Memory: 8.4 MB*\

class Solution {

    
public:
    int DFS(vector<int>& nums, int level, int target, int sum){
        if (level == nums.size()){
            if (sum == target) return 1;
            return 0;
        }
        

        int plus = DFS(nums, level+1, target, sum + nums[level]);
        int minus = DFS(nums, level+1, target, sum - nums[level]);
        
        return plus+minus;;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return DFS(nums, 0, S, 0);
    }
};