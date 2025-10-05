class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count1 = 0
        count2 = 0
        element1 = -sys.maxsize - 1
        element2 = -sys.maxsize - 1

        for i in range(0,len(nums)):
            if(nums[i] == element1):
                count1+=1
            elif(nums[i] == element2):
                count2+=1
            elif(count1 == 0):
                element1 = nums[i]
                count1 = 1
            elif(count2 == 0):
                element2 = nums[i]
                count2 = 1
            else:
                count1-=1
                count2-=1

        ans = []
        maxNum = len(nums)//3
        count1 = 0
        count2 = 0
        for i in range (0,len(nums)):
            if(nums[i] == element1):
                count1+=1
            elif(nums[i] == element2):
                count2+=1

        if(count1 > maxNum): 
            ans.append(element1)
        if(count2 > maxNum): 
            ans.append(element2)

        return ans