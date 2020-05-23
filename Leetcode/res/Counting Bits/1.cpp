\*
Author: allannozomu
Runtime: 52 ms
Memory: 9.6 MB*\

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = vector<int> (num + 1);
        int power_index;
        
        power_index = 0;
        for (int i = 1; i <= num; ++i){
            if (i == (1 << power_index)){
                res[i] = 1;
                power_index++;
            } else {
                res[i] = 1 + res[i - (1 << (power_index - 1))];
            }
        }
        return res;
    }
};