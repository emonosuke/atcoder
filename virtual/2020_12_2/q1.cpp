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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll prev = a[0], ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < prev)
        {
            ans += (prev - a[i]);
        }
        else
        {
            prev = a[i];
        }
    }
    cout << ans << endl;
}
