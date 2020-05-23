\*
Author: allannozomu
Runtime: 24 ms
Memory: 11.5 MB*\

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() <= 1) return false;
        
        unordered_map<int, int> memo;
        memo[0] = -1;
        
        int sum = 0;
        
        for (int i = 0 ; i < nums.size(); ++i){
            sum += nums[i];
            int index = (k == 0) ? sum : sum % k;
            auto pos = memo.find(index) ;
            if (pos != memo.end()){
                if (i - pos->second > 1)
                    return true;
            } else {
                memo[index] = i;
            }
        }
        return false;
    }
};