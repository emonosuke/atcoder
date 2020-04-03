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
    string s; cin >> s;
    vector<ll> sumv;
    sumv.push_back(0);
    sumv.push_back(0);
    char c = s[0];
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        if(s[i] == c){
            cnt++;
        }else{
            c = s[i];
            sumv.push_back(sumv.back() + cnt);
            cnt = 0;
            cnt++;
        }
    }
    sumv.push_back(sumv.back() + cnt);
    sumv.push_back(sumv.back());

    ll sz = sumv.size();
    ll ans = 0;
    if(s[0] == '1'){
        if(2 + 2*k >= sz){
            ans = n;
        }
        // 1 0 1 ...
        for(ll i=2;i+2*k<sz;i+=2){
            ans = max(ans, sumv[i+2*k] - sumv[i-1]);
        }   
    }else{
        if(1 + 2*k >= sz){
            ans = n;
        }
        // 0 1 0 ...
        for(ll i=1;i+2*k<sz;i+=2){
            ans = max(ans, sumv[i+2*k] - sumv[i-1]);
        }
    }
    cout << ans << endl;
}
