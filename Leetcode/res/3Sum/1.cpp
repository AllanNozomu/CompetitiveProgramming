\*
Author: allannozomu
Runtime: 108 ms
Memory: 14.6 MB*\

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2) return {};
        
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        int left, right;
        
        for (int slow = 0; slow < nums.size() - 2; ++slow){
            int left = slow + 1;
            int right = nums.size() - 1;
            
            while(left < right){
                int sum = nums[slow] + nums[left] + nums[right];
                if (sum == 0){
                    res.push_back({nums[slow], nums[left], nums[right]});
                    
                    while(left < nums.size() - 2 && nums[left] == nums[left + 1])
                        left++;
                    while(right > 0 && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                } else if (sum < 0){
                    while(left < nums.size() - 2 && nums[left] == nums[left + 1])
                        left++;
                    left++;
                } else{
                    while(right > 0 && nums[right] == nums[right - 1])
                        right--;
                    right--;
                }
            }
            while(slow < nums.size() - 2 && nums[slow] == nums[slow + 1])
                slow++;
        }
        

        return res;
    }
};