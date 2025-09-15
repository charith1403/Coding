class Solution {
    public void setZeroes(int[][] matrix) {
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();

        for(int i=0;i<matrix.length;i++)
        {
            for(int j=0;j<matrix[0].length;j++)
            {
                if(matrix[i][j] == 0)
                {
                    arr.add(new ArrayList<>(Arrays.asList(i,j)));
                }
            }
        }

        for(ArrayList<Integer> pos : arr)
        {
            int ipos = pos.get(0);
            int jpos = pos.get(1);

            for(int j=0;j<matrix[0].length;j++)
            {
                matrix[ipos][j] = 0;
            }

             for(int i=0;i<matrix.length;i++)
            {
                matrix[i][jpos] = 0;
            }
        }

    }
}