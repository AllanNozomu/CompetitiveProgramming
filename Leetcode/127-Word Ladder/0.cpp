class Solution {
public:
    string changeOneCharacter(string a, int i){
        a[i] = '*';
        return a;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> str_to_combo;
        unordered_map<string, vector<string>> combo_to_str;
        int str_size = beginWord.size();
        
        for (string word : wordList){
            for (int j = 0 ; j < str_size; ++j){
                string modified_word = changeOneCharacter(word, j);
                str_to_combo[word].push_back(modified_word);
                combo_to_str[modified_word].push_back(word);
            }
        }
        
        for (int j = 0 ; j < str_size; ++j){
                string modified_word = changeOneCharacter(beginWord, j);
                str_to_combo[beginWord].push_back(modified_word);
                combo_to_str[modified_word].push_back(beginWord);
            }
        
        unordered_map<string, int> visited;
        visited[beginWord] = 1;
        queue<pair<int, string>> next_nodes;
        next_nodes.push({1, beginWord});
        
        while(!next_nodes.empty()){
            pair<int, string> curr_node = next_nodes.front();
            next_nodes.pop();
            if (curr_node.second == endWord) return curr_node.first;
            
            for (string modified : str_to_combo[curr_node.second]){
                for (string neighbour : combo_to_str[modified]){
                    if (!visited[neighbour]) {
                        visited[neighbour] = 1;
                        next_nodes.push({curr_node.first + 1, neighbour});
                    }
                }
            }
        }
        return false;
    }
};