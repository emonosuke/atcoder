#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};
const int MAX_N = 100000;

vector<vector<int>> friends(MAX_N);
vector<vector<int>> blocks(MAX_N);
vector<bool> visited(MAX_N);
vector<int> num_connect(MAX_N);
vector<int> group_connect(MAX_N);

int dfs1(int u)
{
    int cnt = 1;
    visited[u] = true;
    for (int v : friends[u])
    {
        if (!visited[v])
            cnt += dfs1(v);
    }
    return cnt;
}

void dfs2(int u, int cnt, int group)
{
    num_connect[u] = cnt;
    group_connect[u] = group;
    for (int v : friends[u])
    {
        if (num_connect[v] == 0)
            dfs2(v, cnt, group);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a - 1].push_back(b - 1);
        friends[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < k; i++)
    {
        int c, d;
        cin >> c >> d;
        blocks[c - 1].push_back(d - 1);
        blocks[d - 1].push_back(c - 1);
    }
    int group = 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int cnt = dfs1(i);
            dfs2(i, cnt, group);
            group++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int num_blocks = 0;
        for (int block : blocks[i])
        {
            // in the same group
            if (group_connect[i] == group_connect[block])
                num_blocks++;
        }

        cout << num_connect[i] - num_blocks - int(friends[i].size()) - 1 << " ";
    }
    cout << endl;
}
