\*
Author: allannozomu
Runtime: 8 ms
Memory: 8.7 MB*\

class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int aux = nums[i];
        nums[i] = nums[j];
        nums[j] = aux;
    }
    
    void reverse_nums(vector<int>& nums, int start, int end){
        if (start == end - 1) return;
        for (int s = start, e = end - 1; s < (start + end) / 2; ++s, e--){
            swap(nums, s, e);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;
        
        int start_index = 0;
        int prev_number = nums[0];
        
        for (int i = 1; i < nums.size(); ++i){
            if (prev_number < nums[i]){
                start_index = i;
            }
            prev_number = nums[i];
        }
        int last;
        if (start_index > 0) {
            for (last = nums.size() - 1; last >= 0 && nums[last] <= nums[start_index - 1]; --last);
            swap(nums, start_index-1, last);
        }
        reverse_nums(nums, start_index, nums.size());
    }
};