class Solution {
public:
    typedef pair<int,int> P;

    int helper(vector<vector<int>> &startEndTime)
    {
        int maxProfit = 0;
        // min-heap of (endTime, totalProfit)
        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto startEnd : startEndTime)
        {
            int start = startEnd[0];
            int end = startEnd[1];
            int profit = startEnd[2];

            // Pop all jobs that have ended before current start
            while(!pq.empty() && start >= pq.top().first)
            {
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }

            // Push current job with profit added to maxProfit so far
            pq.push({end, maxProfit + profit});
        }

        // At the end, find the max profit remaining in heap
        while(!pq.empty())
        {
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }

        return maxProfit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> startEndTime;

        for(int i=0;i<startTime.size();i++)
        {
            startEndTime.push_back({startTime[i],endTime[i],profit[i]});
        }

        // Explicitly sort by start time
        sort(startEndTime.begin(), startEndTime.end());

        return helper(startEndTime);
    }
};
