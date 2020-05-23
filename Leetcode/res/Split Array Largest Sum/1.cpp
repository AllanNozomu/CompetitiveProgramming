\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.5 MB*\

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long right = 0;
        for (int num : nums){
            right += num;
        }
        long long left = nums.size() - m;
        
        while(left < right){
            long long mid = (left + right) / 2;
            long long curr = 0;
            int subarray_count = 1;
            int passed = 1;
            
            // cout << mid << endl;
            for (int i = 0 ; i < nums.size(); ++i){
                int num = nums[i];
                if (curr + num == mid){
                    curr = 0;
                    if (i < nums.size() - 1)
                        subarray_count++;
                } else if (curr + num > mid) {
                    curr = num;
                    subarray_count++;
                } else {
                    curr += num;
                }
                if (subarray_count > m || num > mid){
                    passed = 0;
                    break;
                }
                // cout << curr << " " << subarray_count << endl;
            }
            // cout << passed << endl << "--" << endl;
            if (passed && curr <= mid ){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};