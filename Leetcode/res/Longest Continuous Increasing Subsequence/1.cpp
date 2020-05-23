\*
Author: allannozomu
Runtime: 16 ms
Memory: 9.4 MB*\

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int res = 1, count = 1;
        int previous = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            if (previous >= nums[i]){
                res = max(res, count);
                count = 1;
            } else {
                count++;
            }
            previous = nums[i];
        }
        return max(res, count);
    }
};