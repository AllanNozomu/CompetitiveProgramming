\*
Author: allannozomu
Runtime: 0 ms
Memory: 9 MB*\

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        
        vector<int> wait = {0};
        vector<int> buy = {- prices[0]};
        vector<int> sell = {0};
        
        for (int i = 1; i < prices.size() ; ++i){
            wait.push_back(max(sell[i - 1], wait[i - 1]));
            buy.push_back(max(buy[i - 1], wait[i - 1] - prices[i]));
            sell.push_back(max(sell[i - 1], buy[i - 1] + prices[i]));
            // cout << max({wait[sell.size() - 1], buy[sell.size() - 1], sell[sell.size() - 1]}) << endl;
        }
        
        return max({wait[prices.size() - 1], buy[prices.size() - 1], sell[prices.size() - 1]});
    }
};