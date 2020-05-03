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
    ll x;
    cin >> x;
    for (ll a = -200; a <= 200; a++)
    {
        for (ll b = -200; b <= 200; b++)
        {
            if (a * a * a * a * a - b * b * b * b * b == x)
            {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}
