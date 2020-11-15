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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h + 1, vector<char>(w + 1));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
            cin >> s[i][j];
    }
    vector<vector<ll>> dp(h + 1, vector<ll>(w + 1)), sumR(h + 1, vector<ll>(w + 1)), sumD(h + 1, vector<ll>(w + 1)), sumRD(h + 1, vector<ll>(w + 1));

    dp[1][1] = 1;
    sumR[1][1] = 1;
    sumD[1][1] = 1;
    sumRD[1][1] = 1;

    for (int k = 3; k <= h + w; k++)
    {
        for (int i = 1; i <= k - 1; i++)
        {
            int j = k - i;
            if (i > h || j > w)
                continue;
            // cout << i << " " << j << endl;

            if (s[i][j] == '#')
            {
                dp[i][j] = 0;
                sumR[i][j] = 0;
                sumD[i][j] = 0;
                sumRD[i][j] = 0;
            }
            else
            {
                // R
                dp[i][j] += sumR[i][j - 1];
                dp[i][j] %= MOD;
                // D
                dp[i][j] += sumD[i - 1][j];
                dp[i][j] %= MOD;
                // RD
                dp[i][j] += sumRD[i - 1][j - 1];
                dp[i][j] %= MOD;

                sumR[i][j] = sumR[i][j - 1] + dp[i][j];
                sumR[i][j] %= MOD;
                sumD[i][j] = sumD[i - 1][j] + dp[i][j];
                sumD[i][j] %= MOD;
                sumRD[i][j] = sumRD[i - 1][j - 1] + dp[i][j];
                sumRD[i][j] %= MOD;
            }
            // cout << dp[i][j] << endl;
        }
    }
    cout << dp[h][w] << endl;
}
