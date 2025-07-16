class Solution {
    StringBuilder temp;
    List<String> ans;

    void helper(int open,int close,int n)
    {
        if(open == n && close == n)
        {
            ans.add(temp.toString());
            return;
        }

        if(open < n)
        {
            temp.append('(');
            helper(open+1,close,n);
            temp.deleteCharAt(temp.length() - 1);
        }

        if(close < open)
        {
            temp.append(')');
            helper(open,close+1,n);
            temp.deleteCharAt(temp.length() - 1);
        }
    }

    public List<String> generateParenthesis(int n) {
        temp = new StringBuilder();
        ans = new ArrayList<String>();
        helper(0,0,n);
        return ans;
    }
}