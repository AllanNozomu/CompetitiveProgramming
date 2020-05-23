\*
Author: allannozomu
Runtime: 20 ms
Memory: N/A*\

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast){
            if (nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for (; slow < nums.size(); ++slow){
            nums[slow] = 0;
        }
    }
};