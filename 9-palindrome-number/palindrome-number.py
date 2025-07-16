class Solution:

    def palindrome(seld, x: str) -> bool:
        low = 0
        high = len(x) - 1

        while(low<high):
            if(x[low] != x[high]):
                return False
            
            low+=1
            high-=1
        
        return True

    def isPalindrome(self, x: int) -> bool:
        if(x < 0):
            return False
        
        return self.palindrome(str(x))
        