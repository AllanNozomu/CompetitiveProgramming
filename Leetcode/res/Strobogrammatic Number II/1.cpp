\*
Author: allannozomu
Runtime: 40 ms
Memory: 24.4 MB*\

class Solution {
public:
    string build_from_mask(vector<char>& mask){
        string res = "";
        for (char c : mask) res += c;
        return res;
    }
    
    void strobogrammaticAux(int level, vector<char>& mask, vector<string>& all_numbers, int n){
        if (level > n - 1 - level){
            all_numbers.push_back(build_from_mask(mask));
            return;
        }
        if (level == n - 1 - level){
            mask[level] = '0';
            all_numbers.push_back(build_from_mask(mask));
            mask[level] = '1';
            all_numbers.push_back(build_from_mask(mask));
            mask[level] = '8';
            all_numbers.push_back(build_from_mask(mask));
            return;
        }
        mask[level] = mask[n - 1 - level] = '0';
        strobogrammaticAux(level + 1, mask, all_numbers ,n);
        mask[level] = mask[n - 1 - level] = '8';
        strobogrammaticAux(level + 1, mask, all_numbers ,n);
        mask[level] = mask[n - 1 - level] = '1';
        strobogrammaticAux(level + 1, mask, all_numbers ,n);
        mask[level] = '6', mask[n - 1 - level] = '9';
        strobogrammaticAux(level + 1, mask, all_numbers ,n);
        mask[level] = '9', mask[n - 1 - level] = '6';
        strobogrammaticAux(level + 1, mask, all_numbers ,n);
    }
    
    vector<string> findStrobogrammatic(int n) {
        vector<string> all_numbers;
        vector<char> mask = vector<char>(n);
        
        if (n == 1){
            return {"1", "8", "0"};
        }
        mask[0] = mask[n - 1] = '1';
        strobogrammaticAux(1, mask, all_numbers, n);
        mask[0] = mask[n - 1] = '8';
        strobogrammaticAux(1, mask, all_numbers, n);
        mask[0] = '9', mask[n - 1] = '6';
        strobogrammaticAux(1, mask, all_numbers, n);
        mask[0] = '6', mask[n - 1] = '9';
        strobogrammaticAux(1, mask, all_numbers, n);
        return all_numbers;
    }
};