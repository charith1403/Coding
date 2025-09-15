class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        arr : List[Tuple[int,int]] = []

        for i in range (0,len(matrix)):
            for j in range (0, len(matrix[0])):
                if(matrix[i][j] == 0):
                    arr.append((i,j))
        

        for pos in arr:
            ipos , jpos = pos

            for i in range (0,len(matrix)):
                matrix[i][jpos] = 0

            for j in range (0, len(matrix[0])):
                matrix[ipos][j] = 0
        
    
        