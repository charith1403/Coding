class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>(Arrays.asList(1)));

        for(int i=0;i<numRows - 1;i++)
        {
            List<Integer> arr = new ArrayList<>();
            int prev = 0;
            int n = ans.get(i).size();

            for(int j=0;j<n;j++)
            {
                arr.add(prev + ans.get(i).get(j));
                prev = ans.get(i).get(j);
            }
            int next = ans.get(i).get(n-1);
            arr.add(next);
            ans.add(arr);
        }

        return ans;
         
    }
}