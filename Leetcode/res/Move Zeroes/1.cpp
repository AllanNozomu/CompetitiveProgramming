\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.4 MB*\

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0, zero_count = 0;
        
        while(fast < nums.size()){
            if (nums[fast] == 0){
                zero_count++;
            } else {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        while(slow < nums.size()){
            nums[slow] = 0;
            slow++;
        }
    }
};