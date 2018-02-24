const int MAXN = 100000 + 10;
const int MOD = (int)(1e9) + 7;
vector<int> adj[MAXN];
int fac[MAXN], rev[MAXN], f[MAXN], subtree[MAXN];
int n;
// a^m-2 mod(m) is found to find MMI
int power(int x, int k, int MOD) {
    if (k == 0) return 1 % MOD;
    long long t = power(x, k / 2, MOD);
    t = (t * t) % MOD;
    if (k % 2 == 1) t = (t * x) % MOD;
    return t;
}
void init() {
    int n = 100000;
    fac[0] = 1;
// i! is found for finding C(i,k)
    for(int i = 1; i <= n; i++) fac[i] = (1LL * i * fac[i - 1]) % MOD;
    for(int i = 0; i <= n; i++) rev[i] = power(fac[i], MOD - 2, MOD);
}

//C(n,k) is found
int combi(int k, int n) {
    return (1LL * fac[n] * ((1LL * rev[k] * rev[n - k]) % MOD)) % MOD;
}