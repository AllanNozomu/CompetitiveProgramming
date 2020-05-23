\*
Author: allannozomu
Runtime: 12 ms
Memory: 9.6 MB*\

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums)
            res ^= num;
        return res;
    }
};