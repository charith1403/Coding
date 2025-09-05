function twoSum(nums: number[], target: number): number[] {
    let mp = new Map<number,number>();

    for(let i=0;i<nums.length;i++)
    {
        mp.set(nums[i],i);
    }

    for(let i=0;i<nums.length;i++)
    {
        if(mp.get(target - nums[i]) != undefined && i != mp.get(target-nums[i]))
        {
            return [mp.get(target-nums[i]),i];
        }
    }

    return [-1];
};