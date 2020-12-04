#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const int MAX_N = 100000;

vector<vector<int>> graph(MAX_N);
vector<int> sign(MAX_N);

void bfs()
{
    queue<int> Q;
    sign[0] = 0;
    Q.push(0);
    while (!Q.empty())
    {
        int room = Q.front();
        Q.pop();

        for (int newroom : graph[room])
        {
            if (sign[newroom] == -1)
            {
                sign[newroom] = room;
                Q.push(newroom);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fill(sign.begin(), sign.end(), -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs();
    for (int i = 0; i < n; i++)
    {
        if (sign[i] == -1)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i < n; i++)
        cout << sign[i] + 1 << endl;
}
