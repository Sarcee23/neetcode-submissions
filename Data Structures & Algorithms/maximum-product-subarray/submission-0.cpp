class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = res;
        int curMax = res;
        for(int i=1;i<nums.size();i++){
           if(nums[i]<0){
            swap(curMin,curMax);
           }
           
           curMax = max(nums[i],curMax*nums[i]);
           curMin = min(nums[i],curMin*nums[i]);

            res = max(res,curMax);
                    }
                    return res;
    }
};
