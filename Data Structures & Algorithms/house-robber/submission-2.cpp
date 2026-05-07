class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if (nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0],nums[1]);
        }
        int prevprev = nums[0]; 
        int prev = max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
           int curr =max(prev, prevprev+nums[i]);
           prevprev= prev;
           prev = curr;
        }
        return prev;
    }
};
