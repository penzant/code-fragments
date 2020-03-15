// For: nCr mod p
// Ref: https://drken1215.hatenablog.com/entry/2018/06/08/210000

const int MOD = 1000000000 + 7;
const int MAX = 2000000;

long long combination(long long N_, long long R_) {
    const int NUM_ = MAX;
    static long long fact[NUM_+1], invfact[NUM_+1], mod_inv[NUM_+1];
    fact[0] = fact[1] = invfact[0] = invfact[1] = mod_inv[1] = 1;
    for (int i = 2; i < NUM_; i++) {
        if (i > N_ && i > R_) break;
        fact[i] = fact[i - 1] * i % MOD;
        mod_inv[i] = mod_inv[MOD % i] * (MOD - MOD / i) % MOD;
        invfact[i] = invfact[i - 1] * mod_inv[i] % MOD;
    }
    return fact[N_] * invfact[R_] % MOD * invfact[N_-R_] % MOD;
}
