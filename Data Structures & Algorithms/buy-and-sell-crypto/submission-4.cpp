class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start=0;
        int end=0;
        int n = prices.size();
        int profit=0;
        int max_val = INT_MIN;
        while(end<n){
            if(prices[start]<prices[end]){
                profit = max(profit, prices[end]-prices[start]);
            }
            else{
                start = end;
            }
            end++;
        }
        return profit;
    }
};
