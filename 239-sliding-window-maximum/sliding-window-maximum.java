class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a,b) ->
            {
                if(a[0] != b[0])
                {
                    return b[0] - a[0]; // descending
                }
                return a[1] - b[1]; // ascending
            }
        );
        ArrayList<Integer> ans = new ArrayList<>();

        for(int i=0;i<k;i++)
        {
            pq.add(new int[]{nums[i],i});
        }

        ans.add(pq.peek()[0]);
        int minIndex = 0;

        for(int i=k;i<nums.length;i++)
        {
            pq.add(new int[] {nums[i],i});
            while(pq.peek()[1] <= minIndex)
            {
                pq.poll();
            }
            minIndex++;
            ans.add(pq.peek()[0]);
        }

        int [] res =  new int[ans.size()];
        for(int i=0;i<ans.size();i++)
        {
            res[i] = ans.get(i);
        }
        
        return res;

    }
}