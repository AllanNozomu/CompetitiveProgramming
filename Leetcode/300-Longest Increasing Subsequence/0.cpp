class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> lis = vector<int>(nums.size(), 1);
        int res = 1;
        
        for (int i = 0 ; i < nums.size(); ++i){
            for (int j = i; j < nums.size(); ++j){
                if (nums[i] < nums[j]){
                    lis[j] = max(lis[j], lis[i] + 1);
                    res = max(res, lis[j]);
                }
            }
        }
        return res;
    }
};