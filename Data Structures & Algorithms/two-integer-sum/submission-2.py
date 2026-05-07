from collections import defaultdict
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        freqMap = {}
        for i,n in enumerate(nums):
            diff = target - n
            if diff in freqMap:
                return [freqMap[diff],i]
            freqMap[n] = i