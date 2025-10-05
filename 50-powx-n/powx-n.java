class Solution {

    public double myPower(double x, long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        double res = 0;
        double temp = myPower(x, n / 2);
        if (n % 2 == 1) {
            res = temp * temp * x;
        } else {
            res = temp * temp;
        }

        return res;
    }

    public double myPow(double x, int n) {
        long N = n;
        if (n < 0) {
            N = -N;
            x = 1 / x;
        }
        return myPower(x, N);
    }
}