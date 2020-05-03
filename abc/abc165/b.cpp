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
    ll m = 100;
    ll y = 0;
    while (m < x)
    {
        m *= 1.01;
        y++;
    }
    cout << y << endl;
}
