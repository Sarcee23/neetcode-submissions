class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0;
        int right = 0;
        int profit = 0;
        while(right<n){
            if(prices[left]<prices[right]){
                profit = max(profit,prices[right]-prices[left]);
                right++;
            }

            else {
                left = right;
                right = left+1;
            }
        }
        return profit;
    }
};
