class Solution {
public:
    void reverseString(vector<char>& s) {
        int q = s.size();
        for (int i = 0; i < q / 2; ++i){
            s[i] ^= s[s.size() - 1 - i];
            s[s.size() - 1 - i] ^= s[i];
            s[i] ^= s[s.size() - 1 - i];
        }
    }
};