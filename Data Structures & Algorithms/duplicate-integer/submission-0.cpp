class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>numSet;
        for(int& num : nums){
            numSet.insert(num);
        }
        return (numSet.size() == nums.size())? false: true;
    }
};