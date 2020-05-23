\*
Author: allannozomu
Runtime: 4 ms
Memory: 9.8 MB*\

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> code_s;
        
        int codes[256];
        for (int i = 0 ; i < 256; ++i) codes[i] = 0;
        int counter = 0;
        
        for (char c : s){
            if (!codes[c]) {
                counter++;
                codes[c] = counter;
            }
            code_s.push_back(codes[c]);
        }
        
        for (int i = 0 ; i < 256; ++i) codes[i] = 0;
        counter = 0;
        
        for (int i = 0 ; i < t.size(); ++i){
            char c = t[i];
            if (!codes[c]) {
                counter++;
                codes[c] = counter;
            }
            if (code_s[i] != codes[c]) return false;
        }
        return true;
    }
};