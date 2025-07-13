class Solution {
public:

    int calculate(vector<int>& nums, int k, int target)
    {
        int value = 0;
        int maxValue = 0;
        for(int num : nums)
        {
            if(num == k) value--;
            if(num == target) value++;

            if(value < 0) value = 0;

            maxValue = max(maxValue,value);
        }
        return maxValue;
    }

    int maxFrequency(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        int original = 0;

        for(auto num : nums)
        {
            mp[num]++;
        }
        
        int maxVal = 0;
        for(auto it : mp)
        {
            maxVal = max(maxVal, calculate(nums,k,it.first));
        }

        return maxVal + mp[k];
    }
};