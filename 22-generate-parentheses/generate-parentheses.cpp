class Solution {
public:

    void helper(int open,int close,string &temp,vector<string> &ans, int n)
    {
        if(open == n && close == n)
        {
            ans.push_back(temp);
            return;
        }

        if(open < n)
        {
            temp.push_back('(');
            helper(open+1,close,temp,ans,n);
            temp.pop_back();

        }
        if(close < open)
        {
            temp.push_back(')');
            helper(open,close+1,temp,ans,n);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> ans;

        helper(0,0,temp,ans,n);
        return ans;
    }
};