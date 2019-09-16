class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<int, int> char_counter;
        for (char c : s){
            char_counter[c]++;
        }
        for (char c : t){
            char_counter[c]--;
            if(char_counter[c] < 0){
                return false;
            }
        }
        return true;
    }
};