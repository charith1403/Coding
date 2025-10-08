class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp:Dict[int,int] = {}
        ans:List[int] = []

        for i in range (0,len(nums)):
            mp[nums[i]] = i

        for i in range (0,len(nums)):
            if((target - nums[i] in mp) and i != mp[target - nums[i]]):
                ans.append(i)
                ans.append(mp[target - nums[i]])
                break
        return ans