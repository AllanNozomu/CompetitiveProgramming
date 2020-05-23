\*
Author: allannozomu
Runtime: 8 ms
Memory: 9 MB*\

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int char_orders[26];
        
        for (int i = 0 ; i < order.size(); ++i){
            char_orders[order[i] - 'a'] = i;
        }
        
        for (int i = 0 ; i < words.size() - 1; ++i){
            string lower_word = words[i];
            string bigger_word = words[i+1];
            
            auto index_lower = lower_word.begin();
            auto index_bigger = bigger_word.begin();
            
            int correct = false;
            
            while(index_lower != lower_word.end() && index_bigger != bigger_word.end() && !correct){
                if (char_orders[*index_lower - 'a'] > char_orders[*index_bigger - 'a']) return false;
                if (char_orders[*index_lower - 'a'] < char_orders[*index_bigger - 'a']) correct = true;
                if (char_orders[*index_lower - 'a'] == char_orders[*index_bigger - 'a']){
                    index_lower++;
                    index_bigger++;
                }
            }
            if (correct) continue;
            
            if (index_bigger == bigger_word.end()) return false;
        }
        
        return true;
    }
};