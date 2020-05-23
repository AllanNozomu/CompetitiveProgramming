\*
Author: allannozomu
Runtime: 48 ms
Memory: 15.4 MB*\

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; ++i){
            char c = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = c;
        }
    }
};