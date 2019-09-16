class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int qty = nums.size();
        int left, right;
        int aux[qty];
        
        aux[qty - 1] = nums[qty - 1];
        for (int i = qty - 2 ; i >= 0; --i){
            aux[i] = min(aux[i + 1], nums[i]);
        }
        for(left = 0; left < qty; ++left){
            if (nums[left] != aux[left]) break;
        }
        
        aux[0] = nums[0];
        for (int i = 1 ; i < qty; ++i){
            aux[i] = max(aux[i - 1], nums[i]);
        }
        for(right = qty - 1; right >= 0; --right){
            if (nums[right] != aux[right]) break;
        }
        
        if (left < right){
            return right - left + 1;
        }
        return 0;
    }
};