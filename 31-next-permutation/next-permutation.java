class Solution {

    public void swap(int[] nums,int index1,int index2)
    {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    public void reverse(int[] nums, int index)
    {
        int start = index;
        int end = nums.length-1;

        while(start < end)
        {
            swap(nums,start,end);
            start++;
            end--;
        }
    }

    public void nextPermutation(int[] nums) {
        int index1 = -1;
        int index2 = -1;

        for(int i=nums.length-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                index1 = i;
                break;
            }
        }

        if(index1 == -1)
        {
            reverse(nums,0);
            return;
        }

        for(int i=nums.length-1;i>index1;i--)
        {
            if(nums[i] > nums[index1])
            {
                index2 = i;
                break;
            }
        }
        
        swap(nums,index1,index2);
        reverse(nums,index1+1);
    }
}