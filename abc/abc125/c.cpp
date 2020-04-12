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
    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> left(n), right(n);
    left[0] = a[0], right[n-1] = a[n-1];
    for(int i=1;i<n;i++) left[i] = gcd(left[i-1], a[i]);
    for(int i=n-2;i>=0;i--) right[i] = gcd(right[i+1], a[i]);
    ll maxg = 0;
    for(int i=0;i<n;i++){
        // (..., a_{i-1}), a_i, (a_{i+1}, ...)
        ll g;
        if(i - 1 >= 0 && i + 1 < n){
            g = gcd(left[i-1], right[i+1]);
        }else if(i - 1 >= 0){
            g = left[i-1];
        }else{
            g = right[i+1];
        }
        maxg = max(g, maxg);
    }
    cout << maxg << endl;
}
