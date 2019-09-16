class Solution {
public:
    string shiftToA(string s){
        string res = "";
        int diff = s[0] - 'a';
        for (int i = 0 ; i < s.size(); ++i){
            int curr_diff = s[i] - diff;
            if (curr_diff < 'a') curr_diff += 'z' - 'a' + 1;
            res += curr_diff;
        }
        return res;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int max_length = 0;
        
        for (string str : strings){
            int length = str.size();
            max_length = max(max_length, length);
        }
        
        unordered_map<string, vector<string>> sequences_group;
        for (string str : strings){
            sequences_group[shiftToA(str)].push_back(str);
        }
        
        vector<vector<string>> res;
        for (auto sequece_group : sequences_group){
            res.push_back(sequece_group.second);
        }
        return res;
    }
};