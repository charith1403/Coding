class Solution:
    def swap(self,nums: List[int],i:int,j:int) -> None:
        temp : int = nums[i]
        nums[i] = nums[j]
        nums[j] = temp

    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        i : int = 0
        j : int = 0
        k : int = len(nums) - 1

        while (i<=k):
            if(nums[i] == 0):
                self.swap(nums,i,j)
                j+=1
                if(nums[i] == 0):
                    i += 1
            
            elif (nums[i] == 2):
                self.swap(nums,i,k)
                k-=1
            else:
                i+=1

        