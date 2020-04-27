#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 2019;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    ll n = s.size();
    vector<ll> cnt(MOD);
    ll tmp = 0;
    cnt[tmp]++;
    ll mul = 1;
    for(ll i=n-1;i>=0;i--){
        // the value of a_{i+1}...a_n
        // 10^{n-(i+1)} a_{i+1} + ... + a_n
        tmp = (ll(s[i] - '0') * mul + tmp) % MOD;
        mul = (mul * 10) % MOD;
        // cout << tmp << endl;
        cnt[tmp]++;
    }
    ll ans = 0;
    for(ll m=0;m<MOD;m++){
        ans += (cnt[m] * (cnt[m] - 1) / 2);
    }
    cout << ans << endl;
}
