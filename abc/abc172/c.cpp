#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1), b(m + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= m; i++)
        cin >> b[i];
    vector<ll> suma(n + 1), sumb(m + 1);
    suma[0] = 0LL;
    sumb[0] = 0LL;
    for (ll i = 1; i <= n; i++)
        suma[i] = suma[i - 1] + a[i];
    for (ll i = 1; i <= m; i++)
        sumb[i] = sumb[i - 1] + b[i];
    ll ans = 0;
    for (ll numa = 0; numa <= n; numa++)
    {
        // choose i books from A
        if (suma[numa] > k)
            break;
        auto iter = upper_bound(sumb.begin(), sumb.end(), k - suma[numa]);
        iter--;
        int numb = int(iter - sumb.begin());
        // cout << numa << " " << k - suma[numa] << " " << numb << endl;
        ans = max(ans, numa + numb);
    }
    cout << ans << endl;
}
