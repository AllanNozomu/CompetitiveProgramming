\*
Author: allannozomu
Runtime: 96 ms
Memory: 14.5 MB*\

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int a, b, c;
        if (nums.size() <= 2){
            return ret;
        }
        
        for (int i = 0; i < nums.size() - 2; ++i){
            a = nums[i];
            
            if (i > 0 && nums[i-1] == a){
                continue;
            }
            
            for (int j = i + 1, k = nums.size() - 1; j < k; ){
                b = nums[j];
                c = nums[k];
                
                if (a + b + c == 0) {
                    ret.push_back(vector<int>({a,b,c}));
                    while(j < nums.size() && nums[j] == b){
                        j++;
                    }
                    while(k > j && nums[k] == b){
                        k--;
                    }
                } else if (a + b + c < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ret;
    }
};