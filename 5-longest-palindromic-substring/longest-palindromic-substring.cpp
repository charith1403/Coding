class Solution {
public:

    string expand(string &s, int low, int high)
    {
        while(low>=0 && high <= s.size() - 1 && s[low] == s[high])
        {
            low--;
            high++;
        }

        return s.substr(low+1,high-low-1);
    }

    string longestPalindrome(string s) {
        
        string oddAns = "";
        string evenAns = "";
        string ans = "";
        for(int i=0;i<s.size();i++)
        {
            oddAns = expand(s,i,i);
            
            if(oddAns.size() > ans.size())
            {
                ans = oddAns;
            }
            evenAns = expand(s,i,i+1);
            if(evenAns.size() > ans.size())
            {
                ans = evenAns;
            }
        }
        return ans;
    }
};