\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.5 MB*\

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        
        for(int i = 1 ; i < prices.size(); ++i){
            if (prices[i - 1] < prices[i]) {
                total += prices[i] - prices[i - 1];
            }
        }
        return total;
    }
};