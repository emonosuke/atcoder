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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> town2step(n + 1);
    vector<ll> step2town(n + 1);
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        a[i] = t - 1;
    }
    fill(town2step.begin(), town2step.end(), -1);
    fill(step2town.begin(), step2town.end(), -1);
    ll town = 0, step = 0;
    while (town2step[town] < 0)
    {
        town2step[town] = step;
        step2town[step] = town;
        step++;
        town = a[town];
    }
    //cout << town << " " << step << endl;
    ll offset = town2step[town];
    ll loop = step - town2step[town];
    //cout << offset << " " << loop << endl;
    if (k <= offset)
    {
        cout << step2town[k] + 1 << endl;
    }
    else
    {
        ll loopstep = (k - offset) % loop;
        cout << step2town[loopstep + offset] + 1 << endl;
    }
}
