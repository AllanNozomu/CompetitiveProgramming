\*
Author: allannozomu
Runtime: 24 ms
Memory: 11.5 MB*\

class Solution {
private:
    int minimun_removed;
    
public:
    string buildFromMask(string& s, vector<int>& mask){
        string res = "";
        for (int i = 0 ; i < mask.size(); ++i){
            if (mask[i]){
                res += s[i];
            }
        }
        return res;
    }
    
    void removeInvalidParenthesesAux(string& s, int level, vector<int>& mask, int open_count, int removed_count, set<string>& substrings){
        if (open_count < 0 || removed_count > minimun_removed) return;
        
        if (level >= s.size()){
            if (open_count == 0){
                if (removed_count == minimun_removed){
                    substrings.insert(buildFromMask(s, mask));
                } else if (removed_count < minimun_removed){
                    minimun_removed = removed_count;
                    substrings = {buildFromMask(s, mask)};
                }
            }
            return;
        }
        char curr_c = s[level];
        if (curr_c == '('){
            mask[level] = 1;
            removeInvalidParenthesesAux(s, level + 1, mask, open_count + 1, removed_count, substrings);
            mask[level] = 0;
            removeInvalidParenthesesAux(s, level + 1, mask, open_count, removed_count + 1, substrings);
        }else if (curr_c == ')'){
            mask[level] = 1;
            removeInvalidParenthesesAux(s, level + 1, mask, open_count - 1, removed_count, substrings);
            mask[level] = 0;
            removeInvalidParenthesesAux(s, level + 1, mask, open_count, removed_count + 1, substrings);
        }else{
            mask[level] = 1;
            removeInvalidParenthesesAux(s, level + 1, mask, open_count, removed_count, substrings);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        minimun_removed = s.size();
        set<string> substrings;
        vector<int> mask = vector<int>(s.size());
        
        removeInvalidParenthesesAux(s, 0, mask, 0, 0, substrings);
        return vector<string>(substrings.begin(), substrings.end());
    }
};