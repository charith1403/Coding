function findDuplicate(nums: number[]): number {
    for (let i:number = 0; i < nums.length; i++)
    {
            let index:number = Math.abs(nums[i]);
        if (nums[index] < 0) {
            return index;
        }

        nums[index] = -nums[index];
    }

    return -1;
};