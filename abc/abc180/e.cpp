#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const int INF = 1000000000;

vector<int> x(17), y(17), z(17);

int dist(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[j] - z[i]);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }
    int dp[(1 << n)][n];
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int s = 1; s < (1 << n); s++)
    {
        for (int v = 0; v < n; v++)
        {
            // v in s
            if (s & (1 << v))
            {
                for (int j = 0; j < n; j++)
                {
                    dp[s][v] = min(dp[s][v], dp[s - (1 << v)][j] + dist(j, v));
                }
            }
        }
    }
    /*
    for (int s = 0; s < (1 << n); s++)
    {
        for (int v = 0; v < n; v++)
        {
            cout << s << " " << v << " " << dp[s][v] << endl;
        }
    }
    */
    cout << dp[(1 << n) - 1][0] << endl;
}
