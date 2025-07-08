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

    void subsets(int index, vector<string> &arr, vector<string> & temp, set<vector<string>> & ans) // CHANGE: ans is a set for unique patterns
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

        // STEP 1: Build visits, sort by timestamp
        vector<tuple<int, string, string>> visits;
        for(int i = 0; i < n; i++)
            visits.push_back({timestamp[i], username[i], website[i]});
        sort(visits.begin(), visits.end());

        // STEP 2: Build per-user visit history (in order)
        unordered_map<string,vector<string>> mp;
        for(auto &t : visits)
        {
            string user = get<1>(t);
            string web = get<2>(t);
            mp[user].push_back(web);
        }

        // STEP 3: For each user, generate all unique 3-sequences and count per pattern
        map<vector<string>, set<string>> ump; // pattern -> set of users

        for(auto &it: mp)
        {
            const string& user = it.first;
            vector<string> &seq = it.second;

            set<vector<string>> patterns; // store all unique patterns for this user
            vector<string> temp;
            subsets(0, seq, temp, patterns); // generate patterns

            for(const auto& p : patterns) {
                ump[p].insert(user);
            }
        }

        // STEP 4: Use your priority queue logic
        priority_queue<pair<int,vector<string>>, vector<pair<int,vector<string>>>, comp> pq;
        for(auto &it : ump)
        {
            pq.push({(int)it.second.size(), it.first});
        }

        return pq.top().second;
    }
};
