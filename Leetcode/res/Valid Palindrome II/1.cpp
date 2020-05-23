\*
Author: allannozomu
Runtime: 96 ms
Memory: 21.9 MB*\

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() <= 1) return true;
        
        int left = 0;
        int right = s.size() - 1;
        bool different = false;
        
        while(left < right){
            if (s[left] != s[right]){
                different = true;
                break;
            } else {
                left ++;
                right --;
            }
        }
        
        if (different){
            different = false;
            int new_left = left + 1;
            int new_right = right;
            
            while(new_left < new_right){
                if (s[new_left] != s[new_right]){
                    different = true;
                    break;
                } else {
                    new_left ++;
                    new_right --;
                }
            }
        }
        
        if (different){
            different = false;
            int new_left = left;
            int new_right = right - 1;
            
            while(new_left < new_right){
                if (s[new_left] != s[new_right]){
                    different = true;
                    break;
                } else {
                    new_left ++;
                    new_right --;
                }
            }
        }
        
        return !different;
    }
};