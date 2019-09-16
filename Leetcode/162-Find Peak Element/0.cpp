class Solution {
public:
    int findPeakElement(vector<int>& nums) {   
        if (nums.size() > 1){
            if (nums[0] > nums[1]){
                return 0;
            }
            if (nums[nums.size() - 1] > nums[nums.size() - 2]){
                return nums.size() - 1;
            }

            int last = nums[0];
            for (int i = 1 ; i < nums.size() - 1; ++i){
                if (last < nums[i] && nums[i] > nums[i + 1]){
                    return i;
                }
            }
        }
        else
            return 0;
    }
};