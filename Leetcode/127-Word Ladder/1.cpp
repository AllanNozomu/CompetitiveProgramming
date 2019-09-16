class Solution {
public:
    int oneDifference(string& a, string& b){
        int difference_count = 0;
        for (int i = 0;  i < a.size() && difference_count <= 1; ++i){
            if (a[i] != b[i]){
                difference_count++;
            }
        }
        return difference_count <= 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> graph;
        int exist = false;
        
        for (int i = 0 ; i < wordList.size(); ++i){
            for (int j = i + 1 ; j < wordList.size(); ++j) {
                if (oneDifference(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for (int j = 0; j < wordList.size(); ++j) {
            if (oneDifference(beginWord, wordList[j])){
                graph[beginWord].push_back(wordList[j]);
                graph[wordList[j]].push_back(beginWord);
            }
        }
        
        unordered_map<string, int> visited;
        visited[beginWord] = 1;
        queue<pair<int, string>> next_nodes;
        next_nodes.push({1, beginWord});
        
        while(!next_nodes.empty()){
            pair<int, string> curr_node = next_nodes.front();
            next_nodes.pop();
            if (curr_node.second == endWord) return curr_node.first;
            
            for (string neighbour : graph[curr_node.second]){
                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    next_nodes.push({curr_node.first + 1, neighbour});
                }
            }
        }
        return false;
    }
};