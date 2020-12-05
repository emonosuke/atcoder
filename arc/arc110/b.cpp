#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const ll SLEN = 30000000000;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    string T;
    cin >> n >> T;

    if (n == 1)
    {
        if (T[0] == '1')
            cout << SLEN * 2 / 3 << endl;
        else
            cout << SLEN / 3 << endl;
        return 0;
    }

    string S = "";
    for (int i = 0; i < 100000; i++)
        S += "110";

    ll ans = 0;
    if (S.substr(0, n) == T)
    {
        ans = (SLEN - (n - 1) + 2) / 3;
    }
    else if (S.substr(1, n) == T)
    {
        ans = (SLEN - (n - 1) + 1) / 3;
    }
    else if (S.substr(2, n) == T)
    {
        ans = (SLEN - (n - 1)) / 3;
    }
    cout << ans << endl;
}
