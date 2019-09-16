class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> memo;
        
        for (int n : nums){
            if (memo[n]){
                return true;
            }
            memo[n] = 1;
        }
        return false;
    }
};