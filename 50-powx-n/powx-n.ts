function myPower(x: number, n: number): number {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }

    let res: number = 0;
    let temp: number = myPower(x, Math.floor(n / 2));
    if (n % 2 == 1) {
        res = temp * temp * x;
    } else {
        res = temp * temp;
    }

    return res;
}

function myPow(x: number, n: number): number {
    if (n < 0) {
        n = -n;
        x = 1 / x;
    }
    return myPower(x, n);
};
