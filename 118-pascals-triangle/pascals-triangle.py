class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans:List[List[int]] = []
        ans.append([1])

        for i in range(0,numRows-1):
            prev:int  = 0
            arr:List[int] = []

            n:int = len(ans[i])

            for j in range(0,n):
                arr.append(prev + ans[i][j])
                prev = ans[i][j]

            next = ans[i][n-1]
            arr.append(next)
            ans.append(arr)
        
        return ans
        