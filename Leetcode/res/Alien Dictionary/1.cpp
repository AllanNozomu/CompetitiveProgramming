\*
Author: allannozomu
Runtime: 4 ms
Memory: 9.8 MB*\

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> pre_requisites;
        unordered_map<char, unordered_set<char>> children;
        
        for (string word : words){
            for (char c : word){
                pre_requisites[c] = {};
            }
        }
        
        string prev = words[0];
        for(int i = 1; i < words.size(); ++i){
            string curr = words[i];
            
            auto curr_it = curr.begin();
            auto prev_it = prev.begin();
            while(curr_it != curr.end() && prev_it != prev.end()){
                if (*curr_it != *prev_it){
                    children[*prev_it].insert(*curr_it);
                    pre_requisites[*curr_it].insert(*prev_it);
                    break;
                }
                curr_it++;
                prev_it++;
            }
            prev = curr;
        }
        
        queue<char> q;
        string alphabet = "";
        int to_remove = 0;
        
        for (auto words_qty : pre_requisites){
            to_remove++;
            if (words_qty.second.size() == 0){
                q.push(words_qty.first);
            }
        }
        
        while(!q.empty()){
            char curr_char = q.front();
            q.pop();
            
            alphabet += curr_char;
            to_remove--;
            
            for (char child : children[curr_char]){
                pre_requisites[child].erase(curr_char);
                if (pre_requisites[child].size() == 0){
                    q.push(child);
                }
            }
        }
        
        
        if (to_remove == 0){
            return alphabet;
        }
        return "";
    }
};