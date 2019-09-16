class Solution {
public:
    int longestPalindrome(string s) {
        bool count[256] = {};
        
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