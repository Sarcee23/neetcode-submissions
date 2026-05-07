class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq(nums.size()+1);
        for(int num : nums){
            freq[num]++;
            if(freq[num] >=2) return true;
        }
        return false;
    }
};