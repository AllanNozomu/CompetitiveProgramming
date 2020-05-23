\*
Author: allannozomu
Runtime: 36 ms
Memory: 12.1 MB*\

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int qty = nums.size();
        vector<int> maximuns = vector<int>(qty);
        vector<int> minimuns = vector<int>(qty);
        
        maximuns[0] = nums[0];
        for (int i = 1 ; i < qty; ++i){
            maximuns[i] = max(maximuns[i - 1], nums[i]);
        }
        minimuns[qty - 1] = nums[qty - 1];
        for (int i = qty - 2 ; i >= 0; --i){
            minimuns[i] = min(minimuns[i + 1], nums[i]);
        }
        
        int left, right;
        for(left = 0; left < qty; ++left){
            if (nums[left] != minimuns[left]) break;
        }
        for(right = qty - 1; right >= 0; --right){
            if (nums[right] != maximuns[right]) break;
        }
        
        if (left < right){
            return right - left + 1;
        }
        return 0;
    }
};