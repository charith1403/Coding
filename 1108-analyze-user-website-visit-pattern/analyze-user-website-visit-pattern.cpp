class Solution {
public:

    struct comp {
      bool operator() (pair<int,vector<string>> a, pair<int,vector<string>> b)
      {
        if(a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
      }  
    };

    void subsets(int index, vector<string> &arr, vector<string> & temp, set<vector<string>> & ans)
    {
        if(temp.size() > 3)
            return;
        if(temp.size() == 3)
        {
            ans.insert(temp);
            return;
        }

        for(int i=index;i<arr.size();i++)
        {
            temp.push_back(arr[i]);
            subsets(i+1,arr,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {

        int n = username.size();
        vector<pair<int, int>> visits; // (timestamp, index in input)
        for(int i = 0; i < n; i++)
        {
            visits.push_back({timestamp[i], i});
        }
        sort(visits.begin(), visits.end()); // sort by timestamp

        unordered_map<string, vector<string>> mp;
        for(auto &p : visits)
        {
            int idx = p.second;
            mp[username[idx]].push_back(website[idx]);
        }

        map<vector<string>, int> ump; // pattern -> number of users

        for(auto &it: mp)
        {
            vector<string> &v = it.second;
            set<vector<string>> patterns; // store unique patterns per user
            vector<string> temp;
            subsets(0, v, temp, patterns);

            for(auto &pat : patterns)
            {
                ump[pat]++;
            }
        }

        priority_queue<pair<int,vector<string>>, vector<pair<int,vector<string>>>,comp> pq;
        for(auto it : ump)
        {
            pq.push({it.second,it.first});
        }

        return pq.top().second;
    }
};
