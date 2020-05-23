\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.3 MB*\

class Solution {
public:
    int scoreOfParentheses(string S) {
        int openCount = 0;
        
        vector<int> v = vector<int> (S.size() / 2);
        
        for (int i = 0; i < S.size(); ++i){
            if (S[i] == '('){
                if (S[i + 1] == ')'){
                    v[openCount]++;
                    i++;
                } else {
                    openCount++;
                }
            } else {
                v[openCount - 1] += v[openCount] * 2;
                v[openCount] = 0;
                openCount--;
            }
        }
        
        return v[0];
    }
};