\*
Author: allannozomu
Runtime: 24 ms
Memory: 11 MB*\

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int qty = nums.size();
        
        for (int num : nums){
            counter[num]++;
        }
        for (pair<int, int> count : counter){
            if (count.second > qty / 2){
                return count.first;
            }
        }
        return -1;
    }
};