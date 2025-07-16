class Solution {

    boolean palindrome(String x)
    {
        int low = 0;
        int high = x.length() - 1;

        while(low<high)
        {
            if(x.charAt(low) != x.charAt(high))
            {
                return false;
            }

            low++;
            high--;
        }
        return true;    
    }

    public boolean isPalindrome(int x) {
        
        if(x < 0) return false;
        return palindrome(String.valueOf(x));
    }
}