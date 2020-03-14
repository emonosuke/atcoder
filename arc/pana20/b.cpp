#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll h, w; cin >> h >> w;
    ll ans;
    if(h == 1 || w == 1){
        ans = 1;
    }else{
        ans = ((w + 1) / 2) * ((h + 1) / 2) + (w - (w + 1) / 2) * (h - (h + 1) / 2);
    }
    cout << ans << endl;
}
