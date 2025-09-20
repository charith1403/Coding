class Solution {
public:

    void reverse(vector<int>&nums,int index)
    {
        int start = index;
        int end = nums.size() - 1;

        while(start<end)
        {
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        
        int index1 = -1;
        int index2 = -1;

        for(int i=nums.size()-2;i>=0;i--)
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

        for(int i=nums.size()-1;i>index1;i--)
        {
            if(nums[i] > nums[index1])
            {
                index2 = i;
                break;
            }
        }

        swap(nums[index1],nums[index2]);
        reverse(nums,index1+1);
    }
};