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
    ll n;
    cin >> n;
    vector<ll> ans;
    for (ll a = 1; a * a <= n; a++)
    {
        if (n % a == 0)
        {
            ans.push_back(a);
            if (a != n / a)
                ans.push_back(n / a);
        }
    }
    sort(ans.begin(), ans.end());
    for (ll a : ans)
        cout << a << endl;
}
