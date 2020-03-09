#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string S; cin >> S;
    int n = S.size();
    if(n %2 == 1){
        cout << "No" << endl;
        return 0;
    }
    bool ans = true;
    for(int i=0;i<n;i+=2){
        string sub = S.substr(i, 2);
        if(sub != "hi") ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
