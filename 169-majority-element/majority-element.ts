function majorityElement(nums: number[]): number {
    let count:number = 0;
    let element:number = 0;

    for(let i:number = 0;i<nums.length;i++)
    {
        if(count == 0)
        {
            count = 1;
            element = nums[i];
        }
        else if(element == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return element;
    
};