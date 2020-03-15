#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<ll> acc(n + 1);
    acc[1] = acc[0];
    for(int i=0;i<n-1;i++){
        if(s[i] == 'A' && s[i+1] == 'C') acc[i+2] = acc[i+1] + 1;
        else acc[i+2] = acc[i+1];
    }
    for(int i=0;i<q;i++){
        int l, r; cin >> l >> r;
        if(l - 2 >= 0 && s[l-2] == 'A' && s[l-1] == 'C'){
            cout << acc[r] - acc[l-1] - 1 << endl;
        }else{
            cout << acc[r] - acc[l-1] << endl;
        }
    }
}
