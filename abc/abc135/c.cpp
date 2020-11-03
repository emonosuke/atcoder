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
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    for (int i = 0; i < n + 1; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(b[i], a[i] + a[i + 1]);
        a[i + 1] = max(a[i + 1] - max(b[i] - a[i], 0LL), 0LL);
    }
    cout << ans << endl;
}
