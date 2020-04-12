#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a %b);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll k; cin >> k;
    ll sum = 0;
    for(ll a=1;a<=k;a++){
        for(ll b=1;b<=k;b++){
            for(ll c=1;c<=k;c++){
                sum += gcd(gcd(a, b), c);
            }
        }
    }
    cout << sum << endl;
}
