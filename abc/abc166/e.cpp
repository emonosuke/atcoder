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
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    unordered_map<ll, ll> mp1;
    unordered_map<ll, ll> mp2;
    for (ll y = 1; y <= n; y++)
    {
        mp1[y - a[y]]++;
    }
    for (ll y = 1; y <= n; y++)
    {
        mp2[y + a[y]]++;
    }
    ll ans = 0;
    for (ll x = 1; x <= n; x++)
    {
        ans += mp1[x + a[x]];
        ans += mp2[x - a[x]];
    }
    cout << ans / 2 << endl;
}
