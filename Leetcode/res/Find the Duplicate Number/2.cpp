\*
Author: allannozomu
Runtime: 568 ms
Memory: 10.1 MB*\

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0 ; i < nums.size(); ++i){
            for (int j = i + 1; j < nums.size(); ++j){
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return -1;
    }
    
};