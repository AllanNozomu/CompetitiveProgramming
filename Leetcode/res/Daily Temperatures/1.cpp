\*
Author: allannozomu
Runtime: 192 ms
Memory: 15.9 MB*\

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int qty = T.size();
        vector<int> memo = vector<int> (qty);
        
        memo[qty- 1] = -1;
        
        for (int i = qty - 2; i >= 0; --i){
            if (T[i] < T[i + 1]){
                memo[i] = i + 1;
            } else {
                int memo_index = memo[i + 1];
                while(memo_index >= 0 && T[i] >= T[memo_index]){
                    memo_index = memo[memo_index];
                }
                memo[i] = memo_index;
            }
        }
        vector<int> res = vector<int>(qty);
        
        for (int i = 0 ; i < qty; ++i){
            if (memo[i] >= 0){
                res[i] = memo[i] - i;
            } else {
                res[i] = 0;
            }
            
        }
        return res;
    }
};