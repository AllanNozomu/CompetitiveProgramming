\*
Author: allannozomu
Runtime: 80 ms
Memory: 9.2 MB*\

class Solution {
public:
    void swap_numbers(vector<int>& nums, int i, int j){
        int aux = nums[i];
        nums[i] = nums[j];
        nums[j] = aux;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size() - k;
        
        while(left <= right){
            int pivot = nums[right];
            int new_index = left;
            
            for (int i = left; i < right; ++i){
                if (nums[i] <= pivot){
                    swap_numbers(nums, i, new_index);
                    new_index++;
                }
            }
            swap_numbers(nums, new_index, right);
            
            if (new_index == index) return pivot;
            
            if (index < new_index){
                right = new_index - 1;
            } else {
                left = new_index + 1;
            }
        }
        return 0;
        
    }
};