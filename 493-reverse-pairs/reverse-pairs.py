class Solution:
    ans:int = 0

    def merge(self,nums:List[int],start:int,mid:int,end:int):
        j:int = mid + 1
        size:int = (end - start) + 1
        temp:List[int] = [0] * size
        
        for i in range(start,mid+1):
            while(j <= end and nums[i] > 2* nums[j]):
                j+=1
            self.ans += j - (mid + 1)
        i:int = start
        k:int = 0
        j = mid + 1
        while(i <= mid and j<=end):
            if(nums[i] <= nums[j]):
                temp[k] = nums[i]
                k+=1
                i+=1
            else:
                temp[k] = nums[j]
                k+=1
                j+=1

        while(i<=mid):
            temp[k] = nums[i]
            k+=1
            i+=1

        while(j <=end):
            temp[k] = nums[j]
            k+=1
            j+=1

        k = 0

        for i in range(start,end+1):
            nums[i] = temp[k]
            k+=1

    def mergeSort(self,nums:List[int],start:int,end:int):
        if(start < end):
            mid:int = (start + end)//2
            self.mergeSort(nums,start,mid)
            self.mergeSort(nums,mid+1,end)
            self.merge(nums,start,mid,end)

    def reversePairs(self, nums: List[int]) -> int:
        self.mergeSort(nums,0,len(nums) - 1)
        return self.ans

        