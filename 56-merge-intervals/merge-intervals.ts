function merge(intervals: number[][]): number[][] {
     if (intervals.length == 1) {
            return intervals;
        }

        // sort(intervals.begin(), intervals.end());
        intervals.sort((a,b) => a[0] - b[0]);
        let start : number = intervals[0][0];
        let end : number = intervals[0][1];
        let ans:number[][] = [];
        let i : number = 1;

        while (i < intervals.length) {
            if (end >= intervals[i][0]) {
                end = Math.max(end, intervals[i][1]);
                i++;
                continue;
            }
            ans.push([start, end]);
            start = intervals[i][0];
            end = intervals[i][1];
            i++;
        }
        ans.push([start, end]);

        return ans;
};