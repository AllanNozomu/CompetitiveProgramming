\*
Author: allannozomu
Runtime: 92 ms
Memory: 13.2 MB*\

class Solution {
public:
    string minWindow(string s, string t) {
        int remaining = t.size();
        int max_res = s.size() + 1;
        pair<int, int> best_pair;
        
        unordered_map<char, int> char_map(1000);
        for (char c : t){
            char_map[c]++;
        }
        int slow = 0, fast = 0;
        for (slow = 0, fast = 0; fast < s.size(); fast++) {
            char c = s[fast];
            if (char_map.find(c) != char_map.end()) {
                if (char_map[c] > 0){
                    remaining--;
                }
                char_map[c]--;
                while(slow <= fast && remaining == 0){
                    cout << fast << " " << slow << endl;
                    if (max_res > fast-slow){
                        cout << fast << " " << slow << endl;
                        max_res = fast-slow;
                        best_pair = {slow, fast};
                    }
                    char slow_c = s[slow];
                    if (char_map.find(slow_c) != char_map.end()){
                        if (char_map[slow_c]++ == 0){
                            remaining++;
                        }
                    }
                    slow++;
                }
            }
        }
        while(slow <= fast && remaining == 0){
            if (max_res > fast-slow){
                max_res = fast-slow;
                cout << fast << " " << slow << endl;
                best_pair = {slow, fast};
            }
            char slow_c = s[slow];
            if (char_map.find(slow_c) != char_map.end()){
                if (char_map[slow_c]++ == 0){
                    remaining++;
                }
            }
            slow++;
        }
        cout << max_res << endl;
        cout << best_pair.first << " " << best_pair.second << endl; 
        if (max_res <= s.size())
            return s.substr(best_pair.first, max_res + 1);
        return "";
    }
};