#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

bool solve1(ll r1, ll c1, ll r2, ll c2)
{
    bool res = false;
    res |= (r1 + c1 == r2 + c2);
    res |= (r1 - c1 == r2 - c2);
    res |= (abs(r1 - r2) + abs(c1 - c2) <= 3);
    return res;
}

bool solve2(ll r1, ll c1, ll r2, ll c2)
{
    bool res = false;
    res |= ((r1 + c1 + r2 + c2) % 2 == 0);
    res |= (abs((r1 + c1) - (r2 + c2)) <= 3);
    res |= (abs((r1 - c1) - (r2 - c2)) <= 3);
    //
    res |= (abs(r1 - r2) + abs(c1 - c2) <= 6);
    return res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll r1, c1, r2, c2;
    // from (r1, c1) to (r2, c2)
    cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 && c1 == c2)
    {
        cout << 0 << endl;
    }
    else if (solve1(r1, c1, r2, c2))
    {
        cout << 1 << endl;
    }
    else if (solve2(r1, c1, r2, c2))
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 3 << endl;
    }
}
