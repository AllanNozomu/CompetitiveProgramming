\*
Author: allannozomu
Runtime: 16 ms
Memory: 9.8 MB*\

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> code_s;
        
        unordered_map<char, int> codes_s;
        
        for (char c : s){
            if (!codes_s[c]) {
                codes_s[c] = codes_s.size() + 1;
            }
            code_s.push_back(codes_s[c]);
        }
        
        unordered_map<char, int> codes_t;
        
        for (int i = 0 ; i < t.size(); ++i){
            char c = t[i];
            if (!codes_t[c]) {
                codes_t[c] = codes_t.size() + 1;
            }
            if (code_s[i] != codes_t[c]) return false;
        }
        return true;
    }
};