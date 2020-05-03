#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> sumv(n + 2);
    sumv[0] = 0;
    for (ll v = 0; v <= n; v++)
        sumv[v + 1] = sumv[v] + v;
    for (ll i = k; i <= n + 1; i++)
    {
        ll vmin = sumv[i];
        ll vmax = sumv[n + 1] - sumv[n + 1 - i];
        // cout << k << " " << vmin << " " << vmax << endl;

        ans += (vmax - vmin + 1);
        ans %= MOD;
    }
    cout << ans << endl;
}
