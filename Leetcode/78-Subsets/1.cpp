class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int qty = nums.size();
        int total = 1 << qty;
        vector<vector<int>> res = vector<vector<int>>(total);
        
        for (int i = 0; i < total; i++){
            for (int j = 0 ; j < qty; ++j){
                if (i & 1 << j){
                   res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};