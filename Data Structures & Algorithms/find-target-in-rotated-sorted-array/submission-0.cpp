class Solution {
public:
    int search(vector<int>& nums, int target) {
      int lo = 0;
      int hi = nums.size() - 1;
      while(lo<= hi){
        int mid = lo + (hi-lo)/2;
        double num = (nums[mid] < nums[0]) == (target < nums[0])?nums[mid]: target< nums[0] ? -INT_MAX: INT_MAX;
        if(num<target){
            lo = mid + 1;
        }
        else if(num>target){
            hi =  mid - 1;
        }
        else{return mid;}

      }
        return -1;
    }
};
