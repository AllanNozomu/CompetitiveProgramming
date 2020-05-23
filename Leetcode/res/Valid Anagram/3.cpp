\*
Author: allannozomu
Runtime: 12 ms
Memory: 9.4 MB*\

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        int char_counter[26] = {0};
        for (char c : s){
            char_counter[c - 'a']++;
        }
        for (char c : t){
            char_counter[c - 'a']--;
            if(char_counter[c - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};