class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum : int = 0
        maxi : int = -sys.maxsize - 1

        for i in range (0,len(nums)):
            sum += nums[i]

            if(sum > maxi):
                maxi = sum
            
            if (sum < 0):
                sum = 0

        return maxi
        