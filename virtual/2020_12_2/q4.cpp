#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dh[4] = {+1, 0, -1, 0};
const int dw[4] = {0, -1, 0, +1};

const int MAX_H = 1000;

int h, w;
vector<string> S(MAX_H);
vector<vector<int>> area(MAX_H, vector<int>(MAX_H));
vector<vector<int>> areagraph(1000000);
vector<int> areadist(1000000);

void bfs(int i, int j, int area_id)
{
    queue<pair<int, int>> Q;
    area[i][j] = area_id;
    Q.push(make_pair(i, j));
    while (!Q.empty())
    {
        pair<int, int> p = Q.front();
        Q.pop();
        int u = p.first, v = p.second;

        for (int k = 0; k < 4; k++)
        {
            int newu = u + dh[k], newv = v + dw[k];
            if (newu < 0 || newu >= h)
                continue;
            if (newv < 0 || newv >= w)
                continue;
            if (S[newu][newv] == '.')
            {
                if (area[newu][newv] != area_id)
                {
                    area[newu][newv] = area_id;
                    Q.push(make_pair(newu, newv));
                }
            }
        }
    }
}

void bfs2(int u)
{
    queue<pair<int, int>> Q; // v, dist
    areadist[u] = 0;
    Q.push(make_pair(u, 0));
    while (!Q.empty())
    {
        pair<int, int> p = Q.front();
        Q.pop();
        ll u = p.first, dist = p.second;
        //
        areadist[u] = dist;
        for (ll v : areagraph[u])
        {
            if (areadist[v] == -1)
            {
                areadist[v] = dist + 1;
                Q.push(make_pair(v, dist + 1));
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    for (int i = 0; i < h; i++)
        cin >> S[i];

    for (int i = 0; i < MAX_H; i++)
        fill(area[i].begin(), area[i].end(), -1);
    fill(areadist.begin(), areadist.end(), -1);
    int area_id = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (S[i][j] == '.' && area[i][j] == -1)
            {
                bfs(i, j, area_id);
                area_id++;
            }
        }
    }

    // cout << area_id << endl;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (S[i][j] == '#')
                continue;
            // (i, j) -> (i + k, j + k)
            for (int k = -2; k <= 2; k++)
            {
                for (int l = -2; l <= 2; l++)
                {
                    int newi = i + k, newj = j + l;
                    if (newi < 0 || newi >= h)
                        continue;
                    if (newj < 0 || newj >= w)
                        continue;
                    if (S[newi][newj] == '#')
                        continue;
                    if (area[i][j] != area[newi][newj])
                    {
                        areagraph[area[i][j]].push_back(area[newi][newj]);
                    }
                }
            }
        }
    }

    int froma = area[ch - 1][cw - 1], toa = area[dh - 1][dw - 1];

    //cout << froma << " " << toa << endl;

    bfs2(froma);

    cout << areadist[toa] << endl;
}
