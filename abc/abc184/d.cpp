#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101)));

double rec(int a, int b, int c)
{
    if (dp[a][b][c])
        return dp[a][b][c];
    if (a == 100 || b == 100 || c == 100)
        return 0;
    double res = 0;
    res += ((double)a / (double)(a + b + c)) * (rec(a + 1, b, c) + 1);
    res += ((double)b / (double)(a + b + c)) * (rec(a, b + 1, c) + 1);
    res += ((double)c / (double)(a + b + c)) * (rec(a, b, c + 1) + 1);
    dp[a][b][c] = res;
    return res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(10) << rec(a, b, c) << endl;
}
