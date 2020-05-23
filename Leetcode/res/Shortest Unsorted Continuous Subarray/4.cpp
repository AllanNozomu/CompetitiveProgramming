\*
Author: allannozomu
Runtime: 60 ms
Memory: 11.4 MB*\

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end());
        
        int l, r;
        
        for ( l = 0; l < nums.size() && nums_copy[l] == nums[l]; ++l);
        for ( r = nums.size() - 1 ; r >=0 && nums_copy[r] == nums[r]; --r);
        if (r < l) return 0;
        return r - l + 1;
    }
};