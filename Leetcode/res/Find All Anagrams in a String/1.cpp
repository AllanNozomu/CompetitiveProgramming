\*
Author: allannozomu
Runtime: 24 ms
Memory: 10.4 MB*\

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int quantity[26] = {0};
        int has_char[26] = {0};
        vector<int> res;
        if (s.size() < p.size()) return res;
        
        for (char c : p){
            quantity[c - 'a']++;
            has_char[c - 'a'] = 1;
        }
        int remaining = p.size();
        for (int i = 0 ; i < p.size(); ++i){
            int add_num = s[i] - 'a';
            if (has_char[add_num]){
                if (quantity[add_num] > 0){
                    remaining--;
                }
                quantity[add_num]--;
            }
        }
        if (remaining == 0){
            res.push_back(0);
        }
        for (int i = p.size(); i < s.size(); ++i){
            int removed_num = s[i - p.size()] - 'a';
            int add_num = s[i] - 'a';
            
            if (has_char[removed_num]){
                if (quantity[removed_num] >= 0){
                    remaining++;
                }
                quantity[removed_num]++;
            }
            if (has_char[add_num]){
                if (quantity[add_num] > 0){
                    remaining--;
                }
                quantity[add_num]--;
            }
            if (remaining == 0){
            res.push_back(i - p.size() + 1);
            }
        }
        return res;
    }
};