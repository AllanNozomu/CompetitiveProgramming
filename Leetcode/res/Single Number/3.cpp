\*
Author: allannozomu
Runtime: 24 ms
Memory: 11.6 MB*\

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> appeared;
        for (int num : nums){
            if (appeared.find(num) == appeared.end())
                appeared.insert(num);
            else
                appeared.erase(num);
        }
        return *appeared.begin();
    }
};