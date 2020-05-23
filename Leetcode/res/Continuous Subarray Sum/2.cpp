\*
Author: allannozomu
Runtime: 56 ms
Memory: 13.1 MB*\

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() <= 1) return false;
        
        vector<int> acc = {0};
        int sum = 0;
        
        for (int i = 0 ; i < nums.size(); ++i){
            sum += nums[i];
            acc.push_back(sum);
        }
        
        k = abs(k);
        
        for (int i = 0; i <= nums.size(); ++i){
            for (int j = i + 2 ; j <= nums.size(); ++j){
                if (k && (acc[j] - acc[i]) % k == 0){
                    return true;
                } else if (acc[j] - acc[i] == 0){
                    return true;
                }
            }
        }
        return false;
    }
};