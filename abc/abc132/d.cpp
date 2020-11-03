#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

ll mod_pow(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll res = mod_pow(x * x % MOD, n / 2);
    // x^n = ((x^2)^(n/2)) * x
    if (n & 1)
        return res = res * x % MOD;
    // x^n = (x^2)^(n/2)
    return res % MOD;
}

// nCk = n!/(n - k)!k! using a/b = a*b^(1e7 - 2)(mod 1e7)
ll comb(ll n, ll k)
{
    if (n < k)
        return 0;
    ll res = 1;
    k = min(n - k, k);
    for (ll i = n - k + 1; i <= n; i++)
        res = (res * i) % MOD;
    for (ll i = 1; i <= k; i++)
        res = (res * mod_pow(i, MOD - 2)) % MOD;
    return res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    // i: number of division
    for (ll i = 1; i <= k; i++)
    {
        // cout << comb(n - k + 1, i) << " " << comb(k - 1, i - 1) << endl;
        ll ans = (comb(n - k + 1, i) * comb(k - 1, i - 1)) % MOD;
        cout << ans << endl;
    }
}
