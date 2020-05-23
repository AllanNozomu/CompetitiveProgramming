\*
Author: allannozomu
Runtime: 8 ms
Memory: 10.6 MB*\

class Solution {
public:
    
    vector<vector<string>> splitString(string& input){
        vector<vector<string>> res;
        vector<string> group = {};
        string str;
        
        for (char c : input){
            if (c == '{') {
                if (str.size()){
                    res.push_back({str});
                    str = "";
                }
                group = {};
            } else if (c == '}'){
                group.push_back(str);
                str = "";
                res.push_back(group);
            } else if (c == ','){
                group.push_back(str);
                str = "";
            } else {
                str.push_back(c);
            }
        }
        if (str.size()){
            res.push_back({str});
        }
        return res;
    }
    
    void expandAux(vector<vector<string>>& subgroups, int level, string acc, set<string>& res){
        if (level == subgroups.size()){
            res.insert(acc);
            return;
        }
        
        for (string& option : subgroups[level]){
            expandAux(subgroups, level+1, acc+option, res);
        }
    }
    
    vector<string> expand(string S) {
        vector<vector<string>> subgroups = splitString(S);
        set<string> res;
        expandAux(subgroups, 0, "", res);
        return vector<string>(res.begin(), res.end());
    }
};