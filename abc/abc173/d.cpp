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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < (n + 1) / 2 - 1; i++)
    {
        ans += a[i];
    }
    for (int i = 0; i < (n + 1) / 2 - 1; i++)
    {
        ans += a[i + 1];
    }
    if (n % 2 == 0)
        ans += a[(n + 1) / 2 - 1];
    cout << ans << endl;
}
