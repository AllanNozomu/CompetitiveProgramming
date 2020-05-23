\*
Author: allannozomu
Runtime: 12 ms
Memory: N/A*\

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> new_nums;
        int zero_count = 0;
        
        for(auto num : nums){
            if (num == 0) {
                zero_count ++;
            } else {
                new_nums.push_back(num);
            }
        }
        for(int i = 0 ; i < zero_count; ++i){
            new_nums.push_back(0);
        }
        for (int i = 0 ; i < new_nums.size(); ++i){
            nums[i] = new_nums[i];
        }
    }
};