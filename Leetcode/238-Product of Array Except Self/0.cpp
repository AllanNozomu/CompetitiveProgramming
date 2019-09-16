class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        bool has_zero = 0;
        int mult = 1;
        
        for (int num : nums){
            if (num == 0){
                if (has_zero){
                    return vector<int>(nums.size());
                }
                has_zero = 1;
            } else {
                mult *= num;
            }
        }
        for (int num : nums){
            if (num == 0){
                res.push_back(mult);
            }else if (has_zero){
                res.push_back(0);
            } else {
                res.push_back(mult / num);
            }
        }
        
        return res;
    }
};