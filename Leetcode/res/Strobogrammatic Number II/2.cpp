\*
Author: allannozomu
Runtime: 40 ms
Memory: 24.5 MB*\

class Solution {
public:
    // 9-6, 6-9, 0-0, 1-1, 8-8
    
    void strobogrammaticAux(int remaining, string acc_l, string acc_r, vector<string>& all_numbers){
        if (remaining == 0){
            all_numbers.push_back(acc_l + acc_r);
            return;
        }
        if (remaining == 1){
            all_numbers.push_back(acc_l + "0" + acc_r);
            all_numbers.push_back(acc_l + "1" + acc_r);
            all_numbers.push_back(acc_l + "8" + acc_r);
            return;
        }
        strobogrammaticAux(remaining - 2, acc_l + "0", "0" + acc_r, all_numbers);
        strobogrammaticAux(remaining - 2, acc_l + "1", "1" + acc_r, all_numbers);
        strobogrammaticAux(remaining - 2, acc_l + "8", "8" + acc_r, all_numbers);
        strobogrammaticAux(remaining - 2, acc_l + "6", "9" + acc_r, all_numbers);
        strobogrammaticAux(remaining - 2, acc_l + "9", "6" + acc_r, all_numbers);
    }
    
    vector<string> findStrobogrammatic(int n) {
        vector<string> all_numbers;
        if (n == 1){
            return {"1", "8", "0"};
        }
        strobogrammaticAux(n - 2, "1", "1", all_numbers);
        strobogrammaticAux(n - 2, "8", "8", all_numbers);
        strobogrammaticAux(n - 2, "6", "9", all_numbers);
        strobogrammaticAux(n - 2, "9", "6", all_numbers);
        return all_numbers;
    }
};