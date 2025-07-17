class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

        pq = []
        ans= []

        for i in range (0,k,1):
            heapq.heappush(pq,(-nums[i],i))

        ans.append(-pq[0][0])
        minIndex = 0

        for i in range (k,len(nums),1):
            heapq.heappush(pq,(-nums[i],i))
            while(pq[0][1] <= minIndex):
                heapq.heappop(pq)
            minIndex += 1
            ans.append(-pq[0][0])
        
        return ans