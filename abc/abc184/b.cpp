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
    int n, x;
    string s;
    cin >> n >> x >> s;
    int ans = x;
    for (char c : s)
    {
        if (c == 'x')
        {
            ans = max(ans - 1, 0);
        }
        else
        {
            ans++;
        }
    }
    cout << ans << endl;
}
