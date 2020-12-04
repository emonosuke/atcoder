#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};
const int INF = 1e9;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    vector<vector<int>> c(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        for (int j = 0; j < b[i]; j++)
            cin >> c[i][j];
    }
    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    for (int i = 0; i < m; i++)
    {
        int open = 0;
        for (int j = 0; j < b[i]; j++)
        {
            open |= (1 << (c[i][j] - 1));
        }
        for (int bits = 0; bits < (1 << n); bits++)
        {
            dp[bits | open] = min(dp[bits | open], dp[bits] + a[i]);
        }
    }
    if (dp[(1 << n) - 1] == INF)
        cout << -1 << endl;
    else
        cout << dp[(1 << n) - 1] << endl;
}
