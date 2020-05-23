\*
Author: allannozomu
Runtime: 16 ms
Memory: 11.9 MB*\

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1;
        int min_distance = words.size();
        
        for (int i = 0 ; i < words.size(); ++i){
            string &word = words[i];
            
            if (word == word1) {
                pos1 = i;
                if (pos1 >= 0 && pos2 >= 0) 
                    min_distance = min(min_distance, abs(pos1 - pos2));
            } else if (word == word2){
                pos2 = i;
                if (pos1 >= 0 && pos2 >= 0) 
                    min_distance = min(min_distance, abs(pos1 - pos2));
            }
        }
        return min_distance;
    }
};