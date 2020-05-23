\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.4 MB*\

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        
        int sum = 0;
        
        for (int num  : nums){
            if (num > 0){
                sum += num;
                res = max(res, sum);
            } else {
                if (sum + num > 0)
                    sum += num;
                else {
                    if (sum == 0)
                        res = max(res, num);
                    else
                        res = max(res, sum);
                    sum = 0;
                }
            }
        }
        if (sum > 0){
            res = max(res, sum);
        }
        return res;
    }
};