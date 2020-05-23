\*
Author: allannozomu
Runtime: 12 ms
Memory: 9.8 MB*\

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1){
            return true;
        }
        
        int max_jump = nums[0];
        if (!max_jump)
            return false;
        
        for (int i = 1 ; i < nums.size() - 1; ++i){
            max_jump = max(max_jump - 1, nums[i]);
            if (!max_jump)
                return false;
        }

        return true;
    }
};