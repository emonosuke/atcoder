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
    vector<bool> has(n);
    for (ll i = 0; i < k; i++)
    {
        ll d;
        cin >> d;
        for (ll i = 0; i < d; i++)
        {
            ll a;
            cin >> a;
            has[a - 1] = true;
        }
    }
    ll cnt = 0;
    for (ll h : has)
    {
        if (!h)
            cnt++;
    }
    cout << cnt << endl;
}
