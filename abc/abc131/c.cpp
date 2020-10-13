#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

ll gcd(ll a, ll b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll divc = b / c - (a - 1) / c, divd = b / d - (a - 1) / d;
    ll divcd = b / lcm(c, d) - (a - 1) / lcm(c, d);
    cout << (b - a + 1) - (divc + divd - divcd) << endl;
}
