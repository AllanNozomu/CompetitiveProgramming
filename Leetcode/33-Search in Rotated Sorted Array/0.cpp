class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int begin = 0, end = nums.size() - 1;
        
        while(begin < end){
            int middle = (begin + end) / 2;
            
            if (nums[middle] == target){
                return middle;
            }
//[3,4,0,1,2]
// [3,1,2]
            if (nums[middle] < nums[end]){
                if (nums[middle] < target && target <= nums[end]){
                    begin = middle + 1;
                } else {
                    end = middle - 1;
                }
            } else {
                if (nums[begin] <= target && target < nums[middle]){
                    end = middle - 1;
                } else {
                    begin = middle + 1;
                }
            }

        }
        if (nums[begin] == target){
            return begin;
        }
        return -1;
    }
};