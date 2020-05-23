\*
Author: allannozomu
Runtime: 68 ms
Memory: 18.3 MB*\

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<int> res;
        if (nums.size() == 0) return res;
        
        for (int i = 0 ; i < k; ++i){
            window.insert(nums[i]);
        }
        res.push_back(*window.rbegin());
        for (int i = k; i < nums.size(); ++i){
            window.erase(window.find(nums[i - k]));
            window.insert(nums[i]);
            res.push_back(*window.rbegin());
        }
        return res;
    }
};