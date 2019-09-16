class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, long long lower, long long upper) {
        if (nums.size() == 0){
            if (lower == upper) return {to_string(lower)};
            return {to_string(lower) + "->" + to_string(upper)};
        }
        vector<string> res;
        
        long long previous = lower - 1;
        for (long long num : nums){
            if (num - previous == 2){
                res.push_back(to_string(previous + 1));
            } else if ((num - previous > 2)){
                res.push_back(to_string(previous + 1) + "->" + to_string(num - 1));
            }
            previous = num;
        }
        if (upper - nums[nums.size() - 1] == 1){
            res.push_back(to_string(nums[nums.size() - 1] + 1));
        } else if (upper - nums[nums.size() - 1] > 1){
            res.push_back(to_string(nums[nums.size() - 1] + 1) + "->" + to_string(upper));
        }
        return res;
    }
};