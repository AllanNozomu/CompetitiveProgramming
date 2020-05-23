\*
Author: allannozomu
Runtime: 8 ms
Memory: 12.9 MB*\

class Solution {
public:
    void helper(vector<int>& nums, vector<int>& subset, int pos, vector<vector<int>>& result){
        if (pos == nums.size()) {
            result.push_back(subset);
            return;
        }
        helper(nums, subset, pos + 1, result);
        subset.push_back(nums[pos]);
        helper(nums, subset, pos + 1, result);
        subset.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        helper(nums, subset, 0, result);
        return result;
    }
};