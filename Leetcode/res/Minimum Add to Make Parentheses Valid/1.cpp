\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.3 MB*\

class Solution {
public:
    int minAddToMakeValid(string S) {
        int open_count = 0;
        int res = 0;
        
        for (int i = 0; i < S.size(); ++i){
            if (S[i] == '('){
                open_count++;
            } else {
                if (open_count == 0){
                    res++;
                } else {
                    open_count--;
                }
            }
        }
        
        open_count = 0;
        for (int i = S.size() - 1; i >= 0; --i){
            if (S[i] == ')'){
                open_count++;
            } else {
                if (open_count == 0){
                    res++;
                } else {
                    open_count--;
                }
            }
        }
        return res;
    }
};