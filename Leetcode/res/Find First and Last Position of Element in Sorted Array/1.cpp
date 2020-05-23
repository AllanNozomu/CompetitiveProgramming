\*
Author: allannozomu
Runtime: 8 ms
Memory: 10.3 MB*\

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (binary_search(nums.begin(), nums.end(), target)){
            auto lower_b = lower_bound(nums.begin(), nums.end(), target);
            auto upper_b = upper_bound(nums.begin(), nums.end(), target);
            res.push_back(lower_b - nums.begin());
            res.push_back(upper_b - nums.begin() - 1);
        }
        else{
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};