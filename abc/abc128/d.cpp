#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin >> v[i];
    ll ans = 0;
    for(ll l=0;l<=min(n, k);l++){
        for(ll r=0;r<=min(n - l, k - l);r++){
            vector<ll> h;
            for(ll i=0;i<=l-1;i++) h.push_back(v[i]);
            for(ll j=n-1;j>=n-r;j--) h.push_back(v[j]);
            sort(h.begin(), h.end());
            ll sumh = accumulate(h.begin(), h.end(), 0LL);
            ll lenh = h.size();
            ans = max(ans, sumh);
            for(ll i=0;i<lenh;i++){
                sumh -= h[i];
                if(i + 1 <= k - l - r) ans = max(ans, sumh);
            }
        }
    }
    cout << ans << endl;
}
