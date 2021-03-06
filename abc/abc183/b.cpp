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
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    double ans = sx + (gx - sx) * (sy / (sy + gy));
    cout << fixed << setprecision(12) << ans << endl;
}
