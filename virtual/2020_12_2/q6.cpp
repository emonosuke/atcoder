#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const ll MAX_C = 1e12 + 1;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    if (accumulate(a.begin(), a.end(), 0LL) <= k)
    {
        cout << 0 << endl;
        return 0;
    }

    // binary search
    auto check = [&](ll v) {
        ll cost = 0;
        for (int i = 0; i < n; i++)
        {
            cost += max(0LL, a[i] - (v / f[i]));
        }
        // cout << v << " " << cost << endl;
        if (cost <= k)
            return true;
        return false;
    };

    ll ok = MAX_C, ng = -1; // the answer exists in [ok, ng) or (ng, ok]
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}
