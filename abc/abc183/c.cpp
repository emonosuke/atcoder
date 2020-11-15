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
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<ll>> t(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t[i][j];
        }
    }
    vector<int> perm; // size n - 1
    for (int i = 1; i < n; i++)
    {
        perm.push_back(i);
    }
    int ans = 0;
    do
    {
        ll sumt = 0;
        sumt += t[0][perm[0]];
        for (int i = 0; i < n - 2; i++)
        {
            sumt += t[perm[i]][perm[i + 1]];
        }
        sumt += t[perm[n - 2]][0];
        if (sumt == k)
            ans++;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
}
