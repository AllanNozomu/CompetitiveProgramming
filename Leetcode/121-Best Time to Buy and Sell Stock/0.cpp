class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int min_value = prices[0];
        int max_profit = 0;

        for (int i = 1; i < n; ++i){
            if (prices[i] < min_value){
                min_value = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - min_value);
            }
        }
        return max_profit;
    }
};