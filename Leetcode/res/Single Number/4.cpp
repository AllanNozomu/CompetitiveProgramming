\*
Author: allannozomu
Runtime: 12 ms
Memory: 9.8 MB*\

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 0;
        for (int num : nums){
            i ^= num;
        }
        return i;
    }
};