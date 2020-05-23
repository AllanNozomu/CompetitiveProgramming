\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.2 MB*\

class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int asteriskCount = 0;
        
        for (int i = 0 ; i < s.size(); ++i){
            if (s[i] == '('){
                openCount++;
            } else if(s[i] == '*'){
                asteriskCount++;
            } else {
                if (openCount){
                    openCount--;
                } else if (asteriskCount){
                    asteriskCount--;
                } else return false;
            }
        }
        
        openCount = 0;
        asteriskCount = 0;
        
        for (int i = s.size() - 1; i >= 0; --i){
            if (s[i] == ')'){
                openCount++;
            } else if(s[i] == '*'){
                asteriskCount++;
            } else {
                if (openCount){
                    openCount--;
                } else if (asteriskCount){
                    asteriskCount--;
                } else return false;
            }
        }
        
        return true;
    }
};