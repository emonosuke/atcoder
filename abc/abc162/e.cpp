#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

ll mod_pow(ll x, ll n){
    if (n == 0) return 1;
    ll res = mod_pow(x * x %MOD, n / 2);
    // x^n = ((x^2)^(n/2)) * x
    if(n & 1) return res = res * x %MOD;
    // x^n = (x^2)^(n/2)
    return res %MOD;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vector<ll> mod_cnt(k+1);
    ll ans = 0;
    for(ll g=k;g>=1;g--){
        if(k / g == 1){
            mod_cnt[g] = 1;
            ans = (ans + g) % MOD;
            continue;
        }
        ll cnt = mod_pow((k / g), n);
        for(ll t=g*2;t<=k;t+=g){
            cnt = (cnt - mod_cnt[t] + MOD) % MOD;
        }
        mod_cnt[g] = cnt;
        ans = (ans + (g * cnt) % MOD) % MOD;
        // cout << ans << endl;
    }
    cout << ans << endl;
}
