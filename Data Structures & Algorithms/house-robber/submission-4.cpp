class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        int robprevprev = 0;
        int robprev = 0;
        for(int num :  nums){
            int temp = max(robprevprev+num, robprev);
            robprevprev = robprev;
            robprev = temp;
        }
        return robprev;

    }
};
