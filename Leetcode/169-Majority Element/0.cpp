class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int qty = nums.size();
        
        for (int num : nums){
            counter[num]++;
            if (counter[num] > qty / 2) return num;
        }
        return -1;
    }
};