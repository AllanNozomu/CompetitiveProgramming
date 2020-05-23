\*
Author: allannozomu
Runtime: 20 ms
Memory: N/A*\

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        
        int slow, previous = nums[0];
        slow = 1;
        
        for (int fast = 1; fast < nums.size(); ++fast){
            if (nums[fast] != previous){
                nums[slow] = nums[fast];
                previous = nums[fast];
                ++slow;
            }
        }
        
        return slow;
    }
};