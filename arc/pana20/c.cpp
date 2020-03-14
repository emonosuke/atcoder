#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll a, b, c; cin >> a >> b >> c;
    // cout << 2 * sqrt(a * b) << " " << c - a - b << endl;
    if(c - a - b <= 0){
        cout << "No" << endl;
    }else if(4 * a * b < (c - a - b) * (c - a - b)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
