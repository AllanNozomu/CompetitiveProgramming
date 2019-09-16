class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i){
            if (nums[i] < 0 || nums[i] > n){
                nums[i] = 0;
            }
        }
        for (int i = 0; i < n; ++i){
            if (abs(nums[i]) && abs(nums[i]) <= n){
                if (nums[abs(nums[i]) - 1]){
                    nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
                } else{
                    nums[abs(nums[i]) - 1] = - (n + 1);
                }
            }
        }
        for (int i = 0; i < n; ++i){
            if (nums[i] >= 0)
                return i + 1;
        }
        return n + 1;
    }
};