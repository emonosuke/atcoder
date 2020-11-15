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
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<vector<int>> rewards(m + 1); // day -> reward
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b; // day, reward
        if (a > m)
            continue;
        rewards[a].push_back(b);
    }
    priority_queue<int> pq;
    for (int day = 1; day <= m; day++)
    {
        for (int reward : rewards[day])
        {
            pq.push(reward);
        }
        // select 1
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}
