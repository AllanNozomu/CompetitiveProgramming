\*
Author: allannozomu
Runtime: 88 ms
Memory: 19.6 MB*\

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        
        for (int num : nums){
            count[num] ++;
        }
        int res = 0;
        for (auto k_v : count){
            if (count.find(k_v.first + 1) != count.end()){
                res = max(res, k_v.second + count[k_v.first + 1]);
            }
        }
        return res;
    }
};