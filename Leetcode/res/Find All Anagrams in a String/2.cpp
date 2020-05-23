\*
Author: allannozomu
Runtime: 52 ms
Memory: 10.6 MB*\

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> quantity;
        vector<int> res;
        
        for (char c : p){
            quantity[c]++;
        }
        int remaining = p.size();
        for (int i = 0 ; i < p.size(); ++i){
            if (quantity.find(s[i]) != quantity.end()){
                if (quantity[s[i]] > 0){
                    remaining--;
                }
                quantity[s[i]]--;
            }
        }
        if (remaining == 0){
            res.push_back(0);
        }
        for (int i = p.size(); i < s.size(); ++i){
            int removed_num = s[i - p.size()];
            int add_num = s[i];
            
            if (quantity.find(removed_num) != quantity.end()){
                if (quantity[removed_num] >= 0){
                    remaining++;
                }
                quantity[removed_num]++;
            }
            if (quantity.find(add_num) != quantity.end()){
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