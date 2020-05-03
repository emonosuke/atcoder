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
    if (n % 2 == 0)
    {
        for (ll i = 1; i <= (m / 2); i++)
        {
            // even
            cout << i << " " << 2 * m + 2 - i << endl;
        }
        for (ll i = (m / 2) + 2; i <= m + 1; i++)
        {
            // odd
            cout << i << " " << 2 * m + 3 - i << endl;
        }
    }
    else
    {
        for (ll i = 1; i <= m; i++)
        {
            cout << i << " " << 2 * m + 1 - i << endl;
        }
    }
}
