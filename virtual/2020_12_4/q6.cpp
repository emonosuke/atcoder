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
    int R, C, k;
    cin >> R >> C >> k;
    vector<vector<ll>> values(R + 1, vector<ll>(C + 1));
    for (int i = 0; i < k; i++)
    {
        int r, c;
        ll v;
        cin >> r >> c >> v;
        values[r][c] = v;
    }
    vector<vector<vector<ll>>> dp(R + 1, vector<vector<ll>>(C + 1, vector<ll>(4)));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (values[i][j] == 0)
            {
                for (int l = 0; l <= 3; l++)
                {
                    dp[i][j][l] = max(dp[i - 1][j][3], dp[i][j - 1][l]);
                }
            }
            else
            {
                // l = 0 (do not pick)
                dp[i][j][0] = max(dp[i - 1][j][3], dp[i][j - 1][0]);
                for (int l = 1; l <= 3; l++)
                {
                    dp[i][j][l] = max(dp[i][j][l - 1], max(dp[i - 1][j][3] + values[i][j], max(dp[i][j - 1][l - 1] + values[i][j], dp[i][j - 1][l])));
                }
            }
        }
    }
    cout << dp[R][C][3] << endl;
}
