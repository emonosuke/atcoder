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
    vector<ll> f(n + 1);
    for (ll x = 1; x <= 100; x++)
    {
        for (ll y = 1; y <= 100; y++)
        {
            for (ll z = 1; z <= 100; z++)
            {
                ll val = x * x + y * y + z * z + x * y + y * z + z * x;
                if (val <= n)
                    f[val]++;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << f[i] << endl;
}
