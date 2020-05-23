\*
Author: allannozomu
Runtime: 4 ms
Memory: 9 MB*\

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int qty = nums.size();
        vector<vector<int>> res = vector<vector<int>>(1 << qty);
        
        for (int i = 0; i < 1 << qty; i++){
            for (int j = 0 ; j < qty; ++j){
                if (i & 1 << j){
                   res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};