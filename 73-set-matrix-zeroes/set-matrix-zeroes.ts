/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {

    let arr :[number,number][] = [];

    for(let i:number = 0;i<matrix.length;i++)
    {
        for(let j:number = 0;j<matrix[0].length;j++)
        {
            if(matrix[i][j] === 0)
            {
                arr.push([i,j]);
            }
        }
    }

    for(let pos of arr)
    {
        let [ipos , jpos] = pos;

        for(let i:number = 0;i<matrix.length;i++)
        {
            matrix[i][jpos] = 0;
        }

        for(let j:number = 0;j<matrix[0].length;j++)
        {
            matrix[ipos][j] = 0;
        }
    }
};