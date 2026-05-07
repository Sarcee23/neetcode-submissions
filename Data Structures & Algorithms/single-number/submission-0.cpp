class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(const int& ele :nums){
            ans^=ele;
        }
        return ans;
    }
};
