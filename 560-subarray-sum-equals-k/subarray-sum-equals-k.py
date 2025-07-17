class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        mp = {}
        count = 0
        totalSum = 0
        mp[0] = 1
        for i in range(len(nums)):
            totalSum += nums[i]
            temp = totalSum - k
            count += mp.get(temp,0)
            mp[totalSum] = mp.get(totalSum,0)+1
        
        return count
        