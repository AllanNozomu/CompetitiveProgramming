\*
Author: allannozomu
Runtime: 24 ms
Memory: 9.6 MB*\

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for (int i = 0 ; i < s.size(); ++i){
            if (s[i] != t[i]) return false;
        }
        
        return true;
    }
};