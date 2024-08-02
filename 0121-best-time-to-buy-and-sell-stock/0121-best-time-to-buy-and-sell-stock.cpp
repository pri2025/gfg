class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)return 0;
        int mini = prices[0];
        int profit = INT_MIN;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] < mini){
                mini = min(mini,prices[i]);
            }
            
            profit = max(profit,prices[i]-mini);
        }
        return profit;
    }
};