class Solution {
public:
    bool palindrome(string x)
    {
        int low = 0;
        int high = x.size() - 1;


        while(low < high)
        {
            if(x[low] != x[high])
            {
                return false;
            }

            low++;
            high--;
        }

        return true;
    }


    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        
        return palindrome(to_string(x));
    }
};