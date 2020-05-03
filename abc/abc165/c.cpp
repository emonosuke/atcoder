#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
const ll MAXN = 10;
const ll MAXM = 10;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

struct C
{
    ll from, to, dist, score;
};

ll n, m, q;
vector<C> conds;

ll rec(vector<ll> pos)
{
    if (pos.size() >= n)
    {
        ll score = 0;
        for (C cond : conds)
        {
            if (pos[cond.to - 1] - pos[cond.from - 1] == cond.dist)
            {
                score += cond.score;
            }
        }
        return score;
    }
    ll maxscore = 0;
    for (ll j = pos.back(); j <= m; j++)
    {
        vector<ll> newpos = pos;
        newpos.push_back(j);
        maxscore = max(rec(newpos), maxscore);
    }
    return maxscore;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (ll i = 0; i < q; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        conds.push_back(C({a, b, c, d}));
    }
    vector<ll> pos = {1};
    cout << rec(pos) << endl;
}
