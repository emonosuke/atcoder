#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second != b.second)
    {
        return a.second <= b.second;
    }
    return a.first <= b.first;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<ll, ll>> tasks;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        tasks.push_back(make_pair(a, b));
    }
    sort(tasks.begin(), tasks.end(), compare);
    ll time = 0;
    for (pair<ll, ll> task : tasks)
    {
        time += task.first;
        if (time > task.second)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
