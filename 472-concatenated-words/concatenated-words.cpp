class Solution {
public:

    bool helper(int index,string word,unordered_set<string> &st,int count, unordered_map<int,bool> &dp)
    {
        if(index > word.size())
        {
            return false;
        }

        if(index == word.size())
        {
            if(count >= 2)
            {
                return true;
            }
        }

        if(dp.find(index) != dp.end())
        {
            return dp[index];
        }

        string w = "";

        for(int i=index;i<word.size();i++)
        {
            w += word[i];
            if(st.find(w) != st.end())
            {
                if(helper(i+1,word,st,count+1,dp))
                {
                    dp[index] = true;
                    return dp[index];
                }
            }
        }

        dp[index] = false;
        return dp[index];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector<string> ans;
        unordered_set<string> st(words.begin(),words.end());
        
        
        for(auto word: words)
        {   
            st.erase(word);
            unordered_map<int,bool> dp;
            if(word.size() != 0 && helper(0,word,st,0,dp))
            {
                ans.push_back(word);
            }
            st.insert(word);
        }

        return ans;
    }
};