class Solution:
    def romanToInt(self, s: str) -> int:
        mp = {}
        sum = 0

        mp['I'] = 1
        mp['V'] = 5
        mp['X'] = 10
        mp['L'] = 50
        mp['C'] = 100
        mp['D'] = 500
        mp['M'] = 1000    

        for i in range(0,len(s),1):

            if(i+1 < len(s) and mp[s[i]] < mp[s[i+1]]):
                sum -= mp[s[i]]
            else:
                sum += mp[s[i]]
        
        return sum

        