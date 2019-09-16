class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapa;
        unordered_set<string> keys;
        
        for (const string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mapa[key].push_back(str);
            keys.insert(key);
        }
        
        vector<vector<string>> res;
        for (auto key : keys){
            res.push_back({});
            for (string str : mapa[key]){
                res[res.size() - 1].push_back(str);
            }
        }
        return res;
    }
};