class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        freqMap = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in freqMap:
                return [freqMap[complement],i]
            else:
                freqMap[nums[i]] = i        
        