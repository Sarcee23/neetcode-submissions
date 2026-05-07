class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pairMap;
        vector<int>ans(2);
        for(int i=0; i< nums.size();i++){
            //check if complement value already exists and if so find its index
            if(pairMap[target-nums[i]]>0){
                int firstIndex = pairMap[target-nums[i]] -1;
              ans[0] = firstIndex;
              ans[1] = i;
              return ans;
            }
            pairMap[nums[i]] = i+1; // store index of current value
        }
        return ans;
    }
};
