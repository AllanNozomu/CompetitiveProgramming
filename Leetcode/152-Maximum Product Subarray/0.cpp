class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int res = nums[0];
        int actualProduct = nums[0];
        
        for (int i = 1; i < nums.size(); ++i){
            int num = nums[i];
            if (num == 0){
                actualProduct = 0;
            } else {
                if (actualProduct == 0)
                    actualProduct = num;
                else
                    actualProduct *= num;
            }
            res = max(res, actualProduct);
        }
        
        actualProduct = nums[nums.size() - 1];
        res = max(res, actualProduct);
        for (int i = nums.size() - 2; i >= 0; --i){
            int num = nums[i];
            if (num == 0){
                actualProduct = 0;
            } else {
                if (actualProduct == 0)
                    actualProduct = num;
                else
                    actualProduct *= num;
            }
            res = max(res, actualProduct);
        }
        
        return res;
    }
};