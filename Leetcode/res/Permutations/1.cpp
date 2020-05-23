\*
Author: allannozomu
Runtime: 12 ms
Memory: 9.5 MB*\

class Solution {
public:
    vector<vector<int>> res;
    vector<int> actual;
    vector<int> used;
    
    void permute_recursive(vector<int>& nums, int avaiable){
        if (avaiable == 0){
            res.push_back(actual);
        }
        for (int i = 0 ; i < nums.size(); ++i){
            if (!used[i]){
                actual.push_back(nums[i]);
                used[i] = 1;
                permute_recursive(nums, avaiable - 1);
                used[i] = 0;
                actual.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<int>(nums.size());
        res = vector<vector<int>>();
        
        permute_recursive(nums, nums.size());
        return res;
    }
};