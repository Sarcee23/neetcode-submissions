class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //edge case
       if(n<2){
        return n? nums[0]:0;
       }
       return max(robber(nums,0,n-2) , robber(nums,1,n-1));
    }

    int robber(vector<int>&nums, int left, int right){
        int prevprev=0, prev=0;
        for(int i=left;i<=right;i++){
            int curr = max(prevprev+nums[i],prev);
           prevprev= prev;
           prev=curr;
        }
        return prev;
    }
};
