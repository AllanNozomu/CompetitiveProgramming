\*
Author: allannozomu
Runtime: 36 ms
Memory: 12.4 MB*\

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res = vector<int>(nums.size(), 1);
        
        int left_right = 1;
        for (int i = 0 ; i < nums.size(); ++i){
            res[i] *= left_right;
            left_right *= nums[i];
        }
        
        int right_left = 1;
        for (int i = nums.size() - 1 ; i >= 0; --i){
            res[i] *= right_left;
            right_left *= nums[i];
        }
        return res;
    }
};