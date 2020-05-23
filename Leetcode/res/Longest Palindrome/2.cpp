\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.9 MB*\

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        
        int res = 0;
        
        for (char c : s){
            if (count[c]) {
                count[c] = 0;
                res += 2;
            } else {
                count[c] = 1;
            }
        }
        
        for (char c : s){
            if (count[c]) return res + 1;
        }
        return res;
    }
};