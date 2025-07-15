class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int startTime = intervals[0][0];
        int endTime = intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            if(endTime >= intervals[i][0])
            {
                endTime = max(endTime,intervals[i][1]);
            }
            else
            {
                ans.push_back({startTime,endTime});
                startTime = intervals[i][0];
                endTime = intervals[i][1];    
            }
        }
        ans.push_back({startTime,endTime});

        return ans;
      
    }
};