// fermat's theorm에서 등장하는 multiplicative inverse function.
int mul_inv_of(int _x) {
    int p = 1e9+5;
    ll x(_x), res(1);
    while (p) {
        if (p & 1) res = (res * x) % P;
        x = (x * x) % P;
        p >>= 1;
    }
    return int(res);
}
