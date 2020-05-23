\*
Author: allannozomu
Runtime: 20 ms
Memory: 11.8 MB*\

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        vector<pair<int, int>> elements;
        vector<int> res = vector<int>(k);
        
        for (auto num : nums){
            counter[num]++;
        }
        
        for (pair<int, int> num_counter : counter){
            elements.push_back({num_counter.second, num_counter.first});
        }
        
        sort(elements.rbegin(), elements.rend());
        
        for (int i = 0 ; i < k; ++i){
            res[i] = elements[i].second;
        }
        
        return res;
    }
};