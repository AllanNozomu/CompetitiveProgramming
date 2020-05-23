\*
Author: allannozomu
Runtime: 40 ms
Memory: 20 MB*\

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapa;
        
        for (const string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mapa[key].push_back(str);
        }
        
        vector<vector<string>> res;
        for (auto key : mapa){
            res.push_back(key.second);
        }
        return res;
    }
};