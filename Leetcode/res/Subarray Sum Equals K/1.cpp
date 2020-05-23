\*
Author: allannozomu
Runtime: 40 ms
Memory: 18 MB*\

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        counter[0] = 1;
        
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if (counter[sum - k])
                res += counter[sum - k];
            counter[sum]++;
        }
        
        return res;

//         2 + 1
//         2 + 2
//         1 2 3 1 -2 2 3
            
//         2 + 0 = 2
//         2 + 1 = 3
//         2 + 2 = 4
//         2 + 4 = 6
//         2 + 5 = 7
//         2 + 4 = 6
        
    }
};