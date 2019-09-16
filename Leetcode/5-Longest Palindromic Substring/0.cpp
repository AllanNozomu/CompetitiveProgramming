class Solution {
private:
    pair<int, int> getPalindromicSubstr(string& s, int left, int right){
        while(s[left] == s[right]){
            left--;
            right++;
            if (left < 0 || right >= s.size()) break;
        }
        return {left+1, right - left - 1};
    }

public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        
        pair<int, int> longestPalindromicSubstr = {0, 0};
        
        for (int mid  = 0; mid < s.size(); ++mid){
            pair<int, int> midSubstr = getPalindromicSubstr(s, mid, mid);
            if (mid > 0){
                pair<int, int> midSubstr2 = getPalindromicSubstr(s, mid-1, mid);
                if (midSubstr2.second > midSubstr.second){
                    midSubstr = midSubstr2;
                }
            }
                
            if (midSubstr.second  > longestPalindromicSubstr.second){
                longestPalindromicSubstr = midSubstr;
            }
        }
        return s.substr(longestPalindromicSubstr.first, longestPalindromicSubstr.second);
    }
};