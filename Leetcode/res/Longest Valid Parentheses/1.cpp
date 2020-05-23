\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.1 MB*\

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int open_count = 0;
        int auxMax = 0;
        int res = 0;
        
        for (int i = 0 ; i < s.size(); ++i){
            if (s[i] == '('){
                open_count++;
            } else {
                if (open_count == 0){
                    res = max(res, auxMax);
                    auxMax = 0;
                } else {
                    open_count--;
                    auxMax += 2;
                    if (open_count == 0){
                        res = max(res, auxMax);
                    }
                }
            }
        }
        open_count = 0;
        auxMax = 0;
        
        for (int i = s.size() - 1 ; i >= 0; --i){
            if (s[i] == ')'){
                open_count++;
            } else {
                if (open_count == 0){
                    res = max(res, auxMax);
                    auxMax = 0;
                } else {
                    open_count--;
                    auxMax += 2;
                    if (open_count == 0){
                        res = max(res, auxMax);
                    }
                }
            }
        }
        
        return res;
    }
};