#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, a, b, c, d, e; cin >> n >> a >> b >> c >> d >> e;
    ll mint = min(a, min(b, min(c, min(d, e))));
    cout << 4 + ((n + (mint - 1)) / mint) << endl;
}
