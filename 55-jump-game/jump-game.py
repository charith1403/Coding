class Solution:
    def canJump(self, nums: List[int]) -> bool:

        reachable = 0
        
        for i in range(0,len(nums),1):

            if(i > reachable):
                return False
            
            reachable = max(reachable,i+nums[i])
            if(reachable > len(nums) - 1):
                break
        
        return True
        