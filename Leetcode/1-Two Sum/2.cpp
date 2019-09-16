class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> appeared_numbers;
        int diff;
        
        for (int i = 0 ; i < nums.size(); ++i){
            diff = target - nums[i];
            if (appeared_numbers[diff]){
                return vector<int>({i, appeared_numbers[diff] - 1});
            }
            appeared_numbers[nums[i]] = i + 1;
        }
    }
};