class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low = 0
        high = (len(matrix) * len(matrix[0])) - 1

        while(low <= high):
            mid = (low + high)//2
            r = mid // len(matrix[0])
            c = mid % len(matrix[0])

            if(matrix[r][c] == target):
                return True
            elif(matrix[r][c] > target):
                high = mid - 1
            else:
                low = mid + 1
        
        return False