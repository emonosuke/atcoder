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
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        if (i % 2 && a % 2)
            cnt++;
    }
    cout << cnt << endl;
}
