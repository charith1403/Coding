function generate(numRows: number): number[][] {
    let ans : number [][] = [];
    ans.push([1]);

    for(let i=0;i<numRows - 1;i++)
    {
        let prev:number = 0;
        let arr:number[] = [];

        for(let j=0;j<ans[i].length;j++)
        {
            arr.push(prev + ans[i][j]);
            prev = ans[i][j];
        }

        let next:number = ans[i].length - 1;
        arr.push(ans[i][next]);
        ans.push(arr);
    }
    return ans;
};