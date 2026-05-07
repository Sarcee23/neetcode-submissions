class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int  n = nums.size();
            if(n<=0){
                return 0;
            }
            vector<int>dp(n+1,0);
            dp[0]=nums[0];
            int maxi=nums[0];
            for(int i=1;i<n;i++){
                dp[i]= nums[i]+ max(0,dp[i-1]);
                maxi=max(maxi,dp[i]);
            }
            return maxi;
    }
};
