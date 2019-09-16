class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2) return {};
        
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        int left, right;
        
        for (int slow = 0; slow < nums.size() - 2; ++slow){
            int left = slow + 1;
            int right = nums.size() - 1;
            
            while(left < right){
                int sum = nums[slow] + nums[left] + nums[right];
                if (sum == 0){
                    res_set.insert({nums[slow], nums[left], nums[right]});
                    left++;
                    right--;
                } else if (sum < 0){
                    left++;
                } else{
                    right--;
                }
            }
        }
        
        vector<vector<int>> res;
        for (auto element : res_set){
            res.push_back(element);
        }
        return res;
    }
};