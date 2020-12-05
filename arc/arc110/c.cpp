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
    ll n;
    cin >> n;
    vector<ll> P(n + 1), Q(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> P[i];
    ll sumQ = 0, sumposQ = 0;
    for (ll i = 1; i <= n; i++)
    {
        Q[i] = P[i] - i;
        sumQ += Q[i];
        if (Q[i] > 0)
            sumposQ += Q[i];
    }
    if (sumQ != 0 || sumposQ != (n - 1))
    {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans;
    ll now = 1;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << Q[i] << " ";
    // }
    // cout << endl;

    while (now < n)
    {
        if (Q[now] > 0 && Q[now + 1] < 0)
        {
            ll tmp1 = Q[now], tmp2 = Q[now + 1];
            Q[now] = tmp2 + 1;
            Q[now + 1] = tmp1 - 1;
            ans.push_back(now);

            // for (int i = 1; i <= n; i++)
            // {
            //     cout << Q[i] << " ";
            // }
            // cout << endl;

            ll now_ = now - 1;
            while (now_ >= 1)
            {
                if (Q[now_] > 0 && Q[now_ + 1] < 0)
                {
                    ll tmp1 = Q[now_], tmp2 = Q[now_ + 1];
                    Q[now_] = tmp2 + 1;
                    Q[now_ + 1] = tmp1 - 1;
                    ans.push_back(now_);
                    now_--;
                }
                else
                {
                    break;
                }
            }
        }
        now++;
    }
    if (ans.size() == n - 1)
    {
        for (ll a : ans)
            cout << a << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
