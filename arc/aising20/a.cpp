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
    ll l, r, d;
    cin >> l >> r >> d;
    ll cnt = 0;
    for (ll i = l; i <= r; i++)
    {
        if (i % d == 0)
            cnt++;
    }
    cout << cnt << endl;
}
