#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    for(int i=0;i<a;i++) cin >> p[i];
    for(int i=0;i<b;i++) cin >> q[i];
    for(int i=0;i<c;i++) cin >> r[i];
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    vector<ll> pqr;
    pqr.insert(pqr.end(), p.begin(), p.begin()+x);
    // cout << pqr.size() << endl;
    pqr.insert(pqr.end(), q.begin(), q.begin()+y);
    // cout << pqr.size() << endl;
    pqr.insert(pqr.end(), r.begin(), r.end());
    // cout << pqr.size() << endl;
    sort(pqr.begin(), pqr.end(), greater<ll>());
    ll ans = accumulate(pqr.begin(), pqr.begin()+x+y, 0LL);
    cout << ans << endl;
}
