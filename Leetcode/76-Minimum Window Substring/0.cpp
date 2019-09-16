class Solution {
public:
    string minWindow(string s, string t) {
        int qty = s.size();
        int remaining = t.size();
        int max_res = s.size() + 1;
        pair<int, int> best_pair;
        
        int char_map[255] = {0};
        int count[255] = {0};
        for (char c : t){
            char_map[c] = 1;
            count[c]++;
        }
        int slow = 0, fast = 0;
        for (slow = 0, fast = 0; fast < qty; fast++) {
            char c = s[fast];
            if (char_map[c]) {
                if (count[c] > 0){
                    remaining--;
                }
                count[c]--;
                while(slow <= fast && remaining == 0){
                    if (max_res > fast-slow){
                        max_res = fast-slow;
                        best_pair = {slow, fast};
                    }
                    char slow_c = s[slow];
                    if (char_map[slow_c]){
                        if (count[slow_c]++ == 0){
                            remaining++;
                        }
                    }
                    slow++;
                }
            }
        }

        if (max_res <= s.size())
            return s.substr(best_pair.first, max_res + 1);
        return "";
    }
};