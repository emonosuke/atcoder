#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    for(ll i=0;i<x;i++) cin >> a[i];
    for(ll i=0;i<y;i++) cin >> b[i];
    for(ll i=0;i<z;i++) cin >> c[i];
    vector<ll> ab;
    for(ll i=0;i<x;i++){
        for(ll j=0;j<y;j++) ab.push_back(a[i] + b[j]);
    }
    sort(ab.begin(), ab.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    vector<ll> ans;
    for(ll i=0;i<min(k, x*y);i++){
        for(ll j=0;j<min(k, z);j++){
            ans.push_back(ab[i] + c[j]);
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    for(ll i=0;i<k;i++) cout << ans[i] << endl;
}
