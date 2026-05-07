class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
         n = len(nums)
         leftpdt = [0]*n
         rightpdt = [0]*n
         res = [0] * n
         leftpdt[0] = rightpdt[n-1] = 1
         for i in range(1,n):
            leftpdt[i]  = nums[i-1] * leftpdt[i-1]
         for i in range(n-2,-1,-1):
            rightpdt[i] = rightpdt[i+1] * nums[i+1]
         for i in range(n):
            res[i] = leftpdt[i] * rightpdt[i]
         return res
