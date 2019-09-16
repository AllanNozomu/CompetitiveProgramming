class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int qty = nums.size();
        int res_qty = qty;
        for (int i = 0 ; i < qty; ++i){
            int curr_index = nums[i] < 0 ? -(nums[i]) : nums[i];
            curr_index--;
            if (nums[curr_index] > 0){
                nums[curr_index] *= -1;
                res_qty--;
            }
        }
        vector<int> res = vector<int>(res_qty);
        for (int i = 0 ; i < qty; ++i){
            if (nums[i] > 0){
                res[--res_qty] = (i + 1);
            }
        }
        return res;
    }
};