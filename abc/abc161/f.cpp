#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

// O(sqrt(n))
vector<ll> get_divisors(ll n){
    vector<ll> divisors;
    for(ll i=1;i*i<=n;i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(i != (n / i)) divisors.push_back(n / i);
        }
    }
    return divisors;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    ll ans = 0;
    // no division
    ans += get_divisors(n - 1).size() - 1;
    // division at least once
    vector<ll> divisors = get_divisors(n);
    for(ll k: divisors){
        if(k == 1) continue;
        ll tmp = n;
        while(tmp % k == 0){
            tmp /= k;
        }
        if(tmp % k == 1) ans++;
    }
    cout << ans << endl;
}
