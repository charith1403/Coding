class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;

        for(int i=0;i<nums.size();i++)
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

        vector<int> ans;
        int maxNum = nums.size()/3;
        count1 = 0;
        count2 = 0;
        for(int i=0;i<nums.size();i++)
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

        if(count1 > maxNum) ans.push_back(element1);
        if(count2 > maxNum) ans.push_back(element2);

        return ans;
    }
};