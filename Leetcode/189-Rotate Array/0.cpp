class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> first = vector<int>(nums.begin(), nums.begin() + nums.size() - k);
        vector<int> second = vector<int>(nums.begin() + nums.size() - k, nums.end());
        second.insert(second.end(), first.begin(), first.end());
        
        nums = second;
    }
};