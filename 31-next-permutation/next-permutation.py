class Solution:

    def reverse(self,nums:List[int],index:int) -> None:
        start : int = index
        end : int = len(nums) - 1

        while(start<end):
            nums[start],nums[end] = nums[end],nums[start]
            start += 1
            end -= 1

    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index1: int = -1
        index2: int = -1

        for i in range (len(nums)-2,-1,-1):
            if(nums[i] < nums[i+1]):
                index1 = i
                break
        
        if(index1 == -1):
            self.reverse(nums,0)
            return
        
        for i in range(len(nums)-1,index1,-1):
            if(nums[i] > nums[index1]):
                index2 = i
                break
        
        nums[index1],nums[index2] = nums[index2],nums[index1]
        self.reverse(nums,index1+1)
