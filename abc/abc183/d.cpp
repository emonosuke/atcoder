#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const ll MINT = 0;
const ll MAXT = 200000;

class LazySegmentTree
{
public:
    ll size;
    vector<ll> dat, lazy;

    LazySegmentTree(ll n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        dat = vector<ll>(2 * size - 1, 0LL);
        lazy = vector<ll>(2 * size - 1, 0LL);
    }

    void eval(ll k, ll l, ll r)
    {
        if (lazy[k] != 0)
        {
            dat[k] += lazy[k];

            // if not bottom of the tree
            if (r - l > 1)
            {
                lazy[k * 2 + 1] += lazy[k] / 2;
                lazy[k * 2 + 2] += lazy[k] / 2;
            }

            lazy[k] = 0;
        }
    }

    // Add x to [l, r)
    void add(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = size;

        eval(k, l, r);

        if (b <= l || r <= a)
            return;

        if (a <= l && r <= b)
        {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else
        {
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
        }
    }

    // Get sum of [l, r)
    ll getSum(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
    {
        if (r < 0)
            r = size;
        if (b <= l || r <= a)
            return 0;

        eval(k, l, r);
        if (a <= l && r <= b)
            return dat[k];
        else
        {
            ll vl = getSum(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = getSum(a, b, k * 2 + 2, (l + r) / 2, r);
            return vl + vr;
        }
    }
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, w;
    cin >> n >> w;
    LazySegmentTree lsg(MAXT);
    for (int i = 0; i < n; i++)
    {
        ll s, t, p;
        cin >> s >> t >> p;
        lsg.add(s, t, p);
    }
    bool ans = true;
    for (int t = MINT; t <= MAXT; t++)
    {
        if (lsg.getSum(t, t + 1) > w)
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
