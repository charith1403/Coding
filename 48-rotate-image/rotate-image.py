class Solution:

    #     public void reverse(int [] arr)
    # {
    #     int start = 0;
    #     int end = arr.length -1;

    #     while(start < end)
    #     {
    #         int temp = arr[start];
    #         arr[start] = arr[end];
    #         arr[end] = temp;

    #         start++;
    #         end--;
    #     }

    # }

    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        for i in range (0,len(matrix),+1):
            for j in range (0,i+1,+1):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for i in range (0,len(matrix)):
            matrix[i].reverse()
        