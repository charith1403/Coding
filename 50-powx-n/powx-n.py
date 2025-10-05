class Solution:
    def myPower(self, x:float, n: int) -> float:
        if (n == 0):
            return 1
        if (n == 1): 
            return x

        res:int = 0
        temp:int = self.myPower(x, n // 2)
        if (n % 2 == 1):
            res = temp * temp * x
        else:
            res = temp * temp

        return res

    def myPow(self, x:float, n:float) -> float:
        if (n < 0):
            n = -n
            x = 1 / x
        return self.myPower(x, n)
    