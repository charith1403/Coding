class Solution {
    public int[][] merge(int[][] intervals) {

        if (intervals.length == 1) {
            return intervals;
        }

        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        int start = intervals[0][0];
        int end = intervals[0][1];
        int i = 1;

        ArrayList<int[]> ans = new ArrayList<>();

        while (i < intervals.length) {
            if (end >= intervals[i][0]) {
                end = Math.max(end, intervals[i][1]);
                i++;
                continue;
            }

            ans.add(new int[] { start, end });
            start = intervals[i][0];
            end = intervals[i][1];
            i++;
        }
        ans.add(new int[] { start, end });

        return ans.toArray(new int[ans.size()][]);
    }
}