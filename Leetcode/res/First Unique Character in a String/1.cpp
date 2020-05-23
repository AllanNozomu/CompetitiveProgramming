\*
Author: allannozomu
Runtime: 40 ms
Memory: 12.7 MB*\

class Solution {
public:
    int firstUniqChar(string s) {
        int memo[26] = {};
        for (auto c : s){
            memo[c - 'a']++;
        }
        for (int i = 0 ; i < s.size(); ++i){
            if (memo[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};