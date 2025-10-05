class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int count1 = 0;
        int count2 = 0;
        int element1 = Integer.MIN_VALUE;
        int element2 = Integer.MIN_VALUE;

        for(int i=0;i<nums.length;i++)
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

        List<Integer> ans = new ArrayList<>();
        int maxNum = nums.length/3;
        count1 = 0;
        count2 = 0;
        for(int i=0;i<nums.length;i++)
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

        if(count1 > maxNum) ans.add(element1);
        if(count2 > maxNum) ans.add(element2);

        return ans;
    }
}