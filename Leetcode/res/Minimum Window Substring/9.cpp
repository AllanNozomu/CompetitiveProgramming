\*
Author: allannozomu
Runtime: 300 ms
Memory: 381 MB*\

class Solution {
public:
    string minWindow(string s, string t) {
        int remaining = t.size();
        
        unordered_map<char, int> char_map;
        unordered_map<char, queue<int>> char_stack;
        for (char c : t){
            char_map[c]++;
            char_stack[c] = queue<int>();
        }
            
        
        vector<int> has_number = vector<int>(s.size());
        
        int fast, slow;
        string res = "";
        for (fast = slow = 0; fast < s.size(); ++fast){
            char c = s[fast];
            if (char_map[c] > 0){
                if (char_map[c] == 1){
                    char_map[c] = -1;
                } else {
                    char_map[c]--;
                }
                char_stack[c].push(fast);
                has_number[fast] = 1;
                remaining--;
            } else if (char_map[c] < 0){
                int first_pos = char_stack[c].front();
                char_stack[c].pop();
                has_number[first_pos] = 0;
                
                char_stack[c].push(fast);
                has_number[fast] = 1;
            }
            while(has_number[slow] == 0 && slow < fast){
                slow++;
            }
            if (remaining == 0){
                if (has_number[fast] ){
                    
                    string now = s.substr(slow, fast-slow + 1);
                    
                    if (res == "" || res.size() > now.size()){
                        res = now;
                    }
                }
            }
        }
        return res;
    }
};