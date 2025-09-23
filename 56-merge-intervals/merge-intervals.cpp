class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> ans;
        int i = 1;

        while (i < intervals.size()) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
                i++;
                continue;
            }
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
            i++;
        }
        ans.push_back({start, end});

        return ans;
    }
};