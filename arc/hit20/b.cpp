#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll na, nb, m; cin >> na >> nb >> m;
    vector<ll> a(na), b(nb);
    for(ll i=0;i<na;i++) cin >> a[i];
    for(ll i=0;i<nb;i++) cin >> b[i];
    ll mina = *min_element(a.begin(), a.end());
    ll minb = *min_element(b.begin(), b.end());
    ll ans = mina + minb;
    for(ll i=0;i<m;i++){
        ll x, y, c; cin >> x >> y >> c;
        ans = min(a[x-1] + b[y-1] - c, ans);
    }
    cout << ans << endl;
}
