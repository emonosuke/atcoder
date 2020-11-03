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
    string s;
    cin >> s;
    // reverse(s.begin(), s.end());
    int n = s.size();
    // initialized with 0
    vector<vector<ll>> dp(n + 1, vector<ll>(13, 0LL));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '?')
        {
            for (int j = 0; j < 13; j++)
            {
                for (int c = 0; c < 10; c++)
                {
                    int nj = (10 * j + c) % 13;
                    dp[i][nj] += dp[i - 1][j];
                    dp[i][nj] %= MOD;
                }
            }
        }
        else
        {
            int c = int(s[i - 1] - '0');
            for (int j = 0; j < 13; j++)
            {
                int nj = (10 * j + c) % 13;
                dp[i][nj] += dp[i - 1][j];
                dp[i][nj] %= MOD;
            }
        }
        /*
        for (int j = 0; j < 10; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
        */
    }
    cout << dp[n][5] << endl;
}
