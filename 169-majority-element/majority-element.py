class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        element = nums[0]

        for i in range(0,len(nums)):
            if(count == 0):
                count = 1
                element = nums[i]
            elif(element == nums[i]):
                count += 1
            else:
                count -= 1

        return element
        