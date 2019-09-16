class Solution {
public:
    bool is_palindrome(string& s, int left, int right){
        while(left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        int size = s.size();
        int total = 0;
        
        for (int i = 0 ; i < size; ++i){
            int left = i;
            int right = i;
            while (left >= 0 && right < size && is_palindrome(s, left, right)){
                total++;
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < size && is_palindrome(s, left, right)){
                total++;
                left--;
                right++;
            }
        }
        return total;
    }
};