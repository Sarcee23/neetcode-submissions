class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<bool>present(n,0);
        for(const int num : nums){
            if(present[num]==1){
                return num;
            }
            else{
                present[num]=1;
            }
        }
        return -1;
    }
};
