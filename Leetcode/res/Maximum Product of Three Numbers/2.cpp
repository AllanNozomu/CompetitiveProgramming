\*
Author: allannozomu
Runtime: 64 ms
Memory: 10.9 MB*\

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        return max(nums[size - 1] * nums[size - 2] * nums[size - 3],
                  nums[0] * nums[1] * nums[size - 1]);
    }
};