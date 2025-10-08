class Solution {
    int ans = 0;
    void merge(int[] nums,int start,int mid,int end)
    {
        int j = mid + 1;
        int size = (end - start) + 1;
        int[] temp = new int[size];

        for(int i = start;i<=mid;i++)
        {
            while(j <= end && nums[i] > 2* (long)nums[j])
            {
                j++;
            }
            ans += j - (mid + 1);
        }
        int i = start;
        int k = 0;
        j = mid + 1;
        while(i <= mid && j<=end)
        {
            if(nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        while(i<=mid)
        {
            temp[k++] = nums[i++];
        }

        while(j <=end)
        {
            temp[k++] = nums[j++];
        }

        k = 0;
        for(i=start;i<=end;i++)
        {
            nums[i] = temp[k++];
        }

    }

    public void mergeSort(int nums[],int start, int end)
    {
        if(start < end)
        {
            int mid = (start + end)/2;
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    }

    public int reversePairs(int[] nums) {
        mergeSort(nums,0,nums.length - 1);
        return ans;
    }
}