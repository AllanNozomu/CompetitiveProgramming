class Solution {
public:
    string changeOneCharacter(string a, int i){
        a[i] = '*';
        return a;
    }
    
    vector<vector<string>> ladderSequence(string &beginWord, string &endWord, unordered_map<string, vector<string>>& combo_to_str, unordered_map<string, int>& str_to_id) {
        unordered_map<string, int> visited;
        visited[beginWord] = 1;
        queue<tuple<int, string, vector<string>>> next_nodes;
        next_nodes.push({1, beginWord, {beginWord}});
        int minLength = 0;
        vector<vector<string>> res;
        
        while(!next_nodes.empty()){
            tuple<int, string, vector<string>> curr_node = next_nodes.front();
            next_nodes.pop();

            if (get<1>(curr_node) == endWord) {
                minLength = get<0>(curr_node);
                res.push_back(get<2>(curr_node));
                continue;
            }
            if (minLength) {
                continue;
            }
            
            for (int i = 0 ; i < get<1>(curr_node).size(); ++i){
                string modified_word = changeOneCharacter(get<1>(curr_node), i);
                for (string &neighbour : combo_to_str[modified_word]){
                    if (!visited[neighbour] || visited[neighbour] == get<0>(curr_node)) {
                        visited[neighbour] = get<0>(curr_node);
                        vector<string> new_vec = get<2>(curr_node);
                        new_vec.push_back(neighbour);
                        next_nodes.push({get<0>(curr_node) + 1, neighbour, new_vec});
                    }
                }
            }
        }
        return res;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> combo_to_str;
        int str_size = beginWord.size();
        unordered_map<string, int> str_to_id;
        
        for (int i = 0; i < wordList.size(); ++i){
            str_to_id[wordList[i]] = i;
        }
        
        for (string &word : wordList){
            for (int j = 0 ; j < str_size; ++j){
                string modified_word = changeOneCharacter(word, j);
                combo_to_str[modified_word].push_back(word);
            }
        }
        
        unordered_map<string, int> visited;
        
        vector<vector<string>> res = ladderSequence(beginWord, endWord, combo_to_str, str_to_id);

        return res;
    }
};