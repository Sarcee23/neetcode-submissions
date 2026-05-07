class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if (n==0){
                return 0;
            }
            //dp[i][0] represents profit on day i in selling
            // dp[i][1] representes profit on day i in buying
            vector<vector<int>> dp(n+2,vector<int>(2,0));
            for(int i=n-1;i>=0;i--){
                dp[i][0] = max(prices[i] + dp[i+2][1],dp[i+1][0]);
                dp[i][1] = max(-prices[i] + dp[i+1][0],dp[i+1][1]);
            }
            return dp[0][1];
    }
};
