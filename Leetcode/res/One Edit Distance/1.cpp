\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.9 MB*\

class Solution {
public:
    bool addOneEditDistance(string smaller, string bigger){
        if (bigger.size() - smaller.size() > 1) return false;
        
        int indexBigger = 0, indexSmaller = 0;
        bool incorrect = false;
        
        while(indexSmaller < smaller.size()){
            if (bigger[indexBigger] != smaller[indexSmaller]){
                if (incorrect) 
                    return false;
                else {
                    incorrect = true;
                    indexBigger++;
                }
            } else {
                indexBigger++;
                indexSmaller++;
            }
        }
        return incorrect || indexSmaller == indexBigger;
    }
    
    bool changeOneEditDistance(string s, string t){
        bool incorrect = false;
        for (int i = 0 ; i < s.size(); ++i){
            if (s[i] != t[i]){
                if (incorrect)
                    return false;
                else
                    incorrect = true;
            }
        }
        return incorrect;
    }
    
    bool isOneEditDistance(string s, string t) {
        if (s.size() == t.size())
            return changeOneEditDistance(s, t);
        if (s.size() < t.size())
            return addOneEditDistance(s, t);
        return addOneEditDistance(t, s);
    }
};