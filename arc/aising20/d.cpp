#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

ll mod_pow(ll x, ll n, ll mod)
{
    if (n == 0)
        return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    // x^n = ((x^2)^(n/2)) * x
    if (n & 1)
        return res = res * x % mod;
    // x^n = (x^2)^(n/2)
    return res % mod;
}

ll count1(ll bit)
{
    ll ret = 0;
    while (bit > 0)
    {
        if (bit % 2)
            ret++;
        bit /= 2;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    string x;
    cin >> x;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (x[i] == '1');
    }
    ll cntp = cnt + 1, cntm = cnt - 1;
    //cout << cntp << " " << cntm << endl;
    ll pcp = 0, pcm = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '1')
        {
            pcp += mod_pow(2, (n - 1 - i), cntp);
            pcp %= cntp;
            if (cntm > 0)
            {
                pcm += mod_pow(2, (n - 1 - i), cntm);
                pcm %= cntm;
            }
        }
    }
    //cout << pcp << " " << pcm << endl;

    for (int i = 0; i < n; i++)
    {
        if (x[i] == '0')
        {
            // cntp
            ll pcp_ = pcp + mod_pow(2, (n - 1 - i), cntp);
            pcp_ %= cntp;
            ll cnt = 1;
            while (pcp_ > 0)
            {
                pcp_ = (pcp_ % count1(pcp_));
                cnt++;
            }
            cout << cnt << endl;
        }
        else
        {
            // cntm
            if (cntm == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                ll pcm_ = pcm - mod_pow(2, (n - 1 - i), cntm) + cntm;
                pcm_ %= cntm;
                ll cnt = 1;
                while (pcm_ > 0)
                {
                    pcm_ = (pcm_ % count1(pcm_));
                    cnt++;
                }
                cout << cnt << endl;
            }
        }
    }
}
