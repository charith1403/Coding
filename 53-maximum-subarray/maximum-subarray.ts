function maxSubArray(nums: number[]): number {
    let sum : number = 0;
    let maxi : number = Number.MIN_SAFE_INTEGER;

    for(let i:number = 0;i<nums.length;i++)
    {
        sum += nums[i];

        if(sum > maxi)
        {
            maxi = sum;
        }

        if(sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
};