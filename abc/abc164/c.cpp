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
    set<string> st;
    for(ll i=0;i<n;i++){
        string s; cin >> s;
        st.insert(s);
    }
    cout << st.size() << endl;
}
