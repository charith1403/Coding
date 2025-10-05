function majorityElement(nums: number[]): number[] {
    let count1:number = 0;
    let count2:number = 0;
    let element1:number = Number.MIN_VALUE;
    let element2:number = Number.MIN_VALUE;

    for(let i:number=0;i<nums.length;i++)
    {
        if(nums[i] == element1)
        {
            count1++;
        }
        else if(nums[i] == element2)
        {
        count2++;
        }
        else if(count1 == 0)
        {
        element1 = nums[i];
        count1 = 1;
        }
        else if(count2 == 0)
        {
        element2 = nums[i];
        count2 = 1;
        }
        else{
        count1--;
        count2--;
        }
    }

    let ans:number[] = [];
    let maxNum:number = nums.length/3;
    count1 = 0;
    count2 = 0;
    for(let i:number=0;i<nums.length;i++)
    {
        if(nums[i] == element1)
        {
            count1++;
        }
        else if(nums[i] == element2)
        {
            count2++;
        }
    }

    if(count1 > maxNum) ans.push(element1);
    if(count2 > maxNum) ans.push(element2);

    return ans;
};