class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0 ; i < nums.size(); ++i){
            int curr_index = nums[i] < 0 ? -(nums[i]) : nums[i];
            curr_index--;
            if (nums[curr_index] > 0){
                nums[curr_index] *= -1;
            }
        }
        vector<int> res;
        for (int i = 0 ; i < nums.size(); ++i){
            if (nums[i] > 0){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};