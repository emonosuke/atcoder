#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x, y) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

ll solve(ll n, ll a, ll b)
{
    // for 1d
    ll nooverlap;
    if (n - a - b < 0)
        nooverlap = 0;
    else
        nooverlap = ((n - a - b + 2) * (n - a - b + 1)) % MOD;
    ll overlap = ((n - a + 1) * (n - b + 1) - nooverlap) % MOD;
    // for 2d
    ll overlap2d = (overlap * overlap) % MOD;
    ll all = (((n - a + 1) * (n - a + 1) % MOD) * ((n - b + 1) * (n - b + 1) % MOD)) % MOD;
    ll ans = ((all - overlap2d) % MOD + MOD) % MOD; // be careful of negative mod
    return ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        ll ans = solve(n, a, b);
        cout << ans << endl;
    }
}
