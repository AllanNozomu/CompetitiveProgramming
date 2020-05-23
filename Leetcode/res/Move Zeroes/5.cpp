\*
Author: allannozomu
Runtime: 24 ms
Memory: 9.6 MB*\

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast, slow;
        for (slow = 0, fast = 0; fast < nums.size(); ++fast){
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