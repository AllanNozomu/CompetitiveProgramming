\*
Author: allannozomu
Runtime: 4 ms
Memory: N/A*\

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secret_map;
        
        for (char c : secret){
            secret_map[c]++;
        }
        
        int bulls = 0;
        int cows = 0;
        vector<int> visited = vector<int>(guess.size());
        
        for (int i = 0 ; i < guess.size(); ++i){
            if (guess[i] == secret[i]){
                bulls++;
                secret_map[guess[i]]--;
                visited[i] = 1;
            }
        }
        
        for (int i = 0 ; i < guess.size(); ++i){
            if (secret_map[guess[i]] && !visited[i]){
                cows++;
                secret_map[guess[i]]--;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};