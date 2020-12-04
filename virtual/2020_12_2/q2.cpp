#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll ans = abs(x - k * d);

    if (x / d <= k && ((x / d) % 2 == k % 2))
    {
        ans = min(ans, x % d);
    }
    if (x / d + 1 <= k && ((x / d) % 2 != k % 2))
    {
        ans = min(ans, abs(x % d - d));
    }
    cout << ans << endl;
}
