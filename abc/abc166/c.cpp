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
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    vector<bool> bad(n);
    for (ll i = 0; i < n; i++)
        bad[i] = false;
    for (ll i = 0; i < n; i++)
        cin >> h[i];
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if (h[a] >= h[b])
        {
            bad[b] = true;
        }
        if (h[a] <= h[b])
        {
            bad[a] = true;
        }
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (!bad[i])
            cnt++;
    }
    cout << cnt << endl;
}
