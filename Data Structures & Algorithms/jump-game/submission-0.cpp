class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastIndex = nums.size()-1;
        for(int i = lastIndex  -1; i>=0;i--){
            if(i+nums[i] >= lastIndex){
                lastIndex = i;
            }
        }
        return lastIndex  == 0;
    }
};
