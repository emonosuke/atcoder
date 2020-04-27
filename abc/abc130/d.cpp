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
    vector<ll> a(n);
    vector<ll> sum(n+1);
    for(ll i=0;i<n;i++) cin >> a[i];
    sum[0] = 0;
    for(ll i=0;i<n;i++) sum[i+1] = sum[i] + a[i];
    ll ans = 0;
    for(ll i=0;i<n;i++){
        // find k where sum[j+1] - sum[i] >= k
        ll j = lower_bound(sum.begin(), sum.end(), sum[i] + k) - sum.begin();
        ans += (n + 1 - j);
    }
    cout << ans << endl;
}
