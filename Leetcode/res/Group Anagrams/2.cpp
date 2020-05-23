\*
Author: allannozomu
Runtime: 48 ms
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
            res.push_back({});
            for (string str : key.second){
                res[res.size() - 1].push_back(str);
            }
        }
        return res;
    }
};