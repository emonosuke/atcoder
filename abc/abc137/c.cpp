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
    cin >> n;
    ll ans = 0;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    unordered_map<string, ll> cnts;
    for (int i = 0; i < n; i++)
    {
        sort(s[i].begin(), s[i].end());
        cnts[s[i]]++;
    }
    for (auto cnt : cnts)
    {
        ans += (cnt.second * (cnt.second - 1)) / 2;
    }
    cout << ans << endl;
}
