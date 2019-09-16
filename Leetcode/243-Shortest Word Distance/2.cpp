class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> word_positions;
        
        for (int i = 0 ; i < words.size(); ++i){
            word_positions[words[i]].push_back(i);
        }
        int min_distance = words.size();
        for (int pos1 : word_positions[word1]){
            for (int pos2 : word_positions[word2]){
                min_distance = min(min_distance, abs(pos1 - pos2));
            }
        }
        return min_distance;
    }
};