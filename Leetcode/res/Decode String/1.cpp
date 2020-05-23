\*
Author: allannozomu
Runtime: 0 ms
Memory: 9 MB*\

class Solution {
public:
    string decodeStringAux(string s, int start, int end){
        string res = "";
        for (int i = start; i < end; ++i){
            char c = s[i];
            
            if (isdigit(c)){
                int number = 0;
                
                while(isdigit(s[i])){
                    number *= 10;
                    number += s[i] - '0';
                    i++;
                }
                int ss_start = i + 1;
                int ss_end = ss_start + 1;
                int open_count = 0;
                while(!(s[ss_end] == ']' && open_count == 0)) {
                    if (s[ss_end] == '[') open_count++;
                    else if (s[ss_end] == ']') open_count--;
                    ss_end++;
                }
                
                i = ss_end;
                string evaluated = decodeStringAux(s, ss_start, ss_end);
                
                for (int times_count = 0; times_count < number; ++times_count){
                    res += evaluated;
                }
            } else {
                res += c;
            }
        }
        return res;
    }
    
    string decodeString(string s) {
       return decodeStringAux(s, 0, s.size());
    }
};