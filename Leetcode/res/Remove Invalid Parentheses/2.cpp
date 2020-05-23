\*
Author: allannozomu
Runtime: 60 ms
Memory: 22.8 MB*\

class Solution {
private:
    int minimun_removed;
    
public:
    
    void removeInvalidParenthesesAux(string& s, int level, string acc, int open_count, int removed_count, set<string>& substrings){
        if (open_count < 0 || removed_count > minimun_removed) return;
        
        if (level >= s.size()){
            if (open_count == 0){
                if (removed_count == minimun_removed){
                    substrings.insert(acc);
                } else if (removed_count < minimun_removed){
                    minimun_removed = removed_count;
                    substrings = {acc};
                }
            }
            return;
        }
        char curr_c = s[level];
        if (curr_c == '('){
            removeInvalidParenthesesAux(s, level + 1, acc + curr_c, open_count + 1, removed_count, substrings);
            removeInvalidParenthesesAux(s, level + 1, acc, open_count, removed_count + 1, substrings);
        }else if (curr_c == ')'){
            removeInvalidParenthesesAux(s, level + 1, acc + curr_c, open_count - 1, removed_count, substrings);
            removeInvalidParenthesesAux(s, level + 1, acc, open_count, removed_count + 1, substrings);
        }else{
            removeInvalidParenthesesAux(s, level + 1, acc + curr_c, open_count, removed_count, substrings);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        minimun_removed = s.size();
        set<string> substrings;
        
        removeInvalidParenthesesAux(s, 0, "", 0, 0, substrings);
        return vector<string>(substrings.begin(), substrings.end());
    }
};