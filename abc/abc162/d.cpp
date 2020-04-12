#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> lr, lg;
    ll cntb = 0;
    vector<bool> existb(n);
    for(ll i=0;i<n;i++){
        if(s[i] == 'R'){
            lr.push_back(i);
        }else if(s[i] == 'G'){
            lg.push_back(i);
        }else{
            cntb++;
            existb[i] = true;
        }
    }
    ll ans = 0;
    for(ll r: lr){
        for(ll g: lg){
            ll numb = cntb;
            if(r < g){
                // RGB, RBG, BRG
                if(g + (g - r) < n && existb[g + (g - r)]) numb--;
                if((g - r) %2 == 0 && existb[r + (g - r)/2]) numb--;
                if(0 <= r - (g - r) && existb[r - (g - r)]) numb--; 
            }else{
                // GRB, GBR, BGR
                if(r + (r - g) < n && existb[r + (r - g)]) numb--;
                if((r - g) %2 == 0 && existb[g + (r - g)/2]) numb--;
                if(0 <= g - (r - g) && existb[g - (r - g)]) numb--; 
            }
            ans += numb;
        }
    }
    cout << ans << endl;
}
