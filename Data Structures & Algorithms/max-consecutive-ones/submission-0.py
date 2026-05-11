class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        seen1 = False
        maxctr = 0
        curctr=0
        for num in nums:
            if num == 1:
                if not seen1:
                    seen1= True
                    
                curctr+=1
            if num ==0:
                if seen1:
                    maxctr= max(maxctr,curctr)
                    curctr= 0
                    seen1 = False
        return max(maxctr,curctr)

                