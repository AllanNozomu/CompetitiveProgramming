class Solution {
public:
    string buildCountAndSay(string s){
        string res = "";
        int count = 1;
        char curr = s[0];
        
        for (int i = 1; i < s.size(); ++i){
            if (curr != s[i]){
                res += to_string(count) + curr;
                curr = s[i];
                count = 1;
            } else {
                count ++;
            }
        }
        res += to_string(count) + curr;
        return res;
    }
    
    string countAndSayAux(string s, int level){
        if (level == 0){
            return s;
        }
        return countAndSayAux(buildCountAndSay(s), level-1);
    }
    
    string countAndSay(int n) {
        return countAndSayAux("1", n-1);
    }
};