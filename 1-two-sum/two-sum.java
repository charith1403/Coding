class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        int[] ans = new int[2];
        for (int i = 0; i < nums.length; i++) {
            mp.put(nums[i],i);
        }

        for (int i = 0; i < nums.length; i++) {
            if(mp.containsKey(target - nums[i]) && i != mp.get(target - nums[i]))
            {
                ans[0] = i;
                ans[1] = mp.get(target - nums[i]);
                break;
            }
        }
        return ans;
    }
}