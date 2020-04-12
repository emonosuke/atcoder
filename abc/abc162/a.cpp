#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s = to_string(n);
    bool ans = false;
    for(char c: s){
        if(c == '7') ans = true;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
