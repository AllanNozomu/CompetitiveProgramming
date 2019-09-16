class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = vector<int> (num + 1);
        int power_index;
        
        for (power_index = 1 ; power_index <= num; power_index <<= 1){
            res[power_index] = 1;
        }
        power_index = 1;
        for (int i = 2; i <= num; ++i){
            if (res[i]){
                power_index <<= 1;
            } else {
                res[i] = 1 + res[i - power_index];
            }
        }
        return res;
    }
};