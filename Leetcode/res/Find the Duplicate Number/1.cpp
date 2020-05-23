\*
Author: allannozomu
Runtime: 12 ms
Memory: 10 MB*\

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            int bigger_count = 0;
            int lower_count = 0;
            for (int num : nums){
                if (num > mid){
                    bigger_count++;
                } else if (num < mid){
                    lower_count++;
                }
            }
            if (lower_count + bigger_count < nums.size() - 1){
                return mid;
            }
            if (lower_count > mid - 1){
                right = mid - 1;
            } else {
                left = mid + 1;
                
            }
        }
        return -1;
    }
};