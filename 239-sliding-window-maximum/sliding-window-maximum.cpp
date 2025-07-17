class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        int minIndex = 0;

        for(int i=k;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            while(pq.top().second <= minIndex)
            {
                pq.pop();
            }
            minIndex++;
            ans.push_back(pq.top().first);

        }
        return ans;
    }
};