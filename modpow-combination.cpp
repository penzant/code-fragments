// For: combination with mod power
// Ref: abc156d in AtCoder

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;

long long modpow(long long x, long long y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        long long res = modpow(x, y / 2);
        return res * res % MOD;
    } else {
        return x * modpow(x, y - 1) % MOD;
    }
}

long long combination(int x, int y) {
    long long res = 1;
    for (int i = 0; i < y; i++) {
        res *= (x - i);
        res %= MOD;
    }
    for (int i = 1; i <= y; i++) {
        res *= modpow(i, MOD - 2);
        res %= MOD;
    }
    return res;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    long long answer = modpow(2, n) - 1;
    answer -= combination(n, a);
    answer -= combination(n, b);
    cout << (answer % MOD + MOD) % MOD << endl;
    return 0;
}
