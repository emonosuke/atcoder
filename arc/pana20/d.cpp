#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const string chars[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

int n;

void rec(string s, int m){
    if(s.size() == n){
        cout << s << endl;
        return;
    }
    for(int i=0;i<m;i++){
        rec(s + chars[i], m);
    }
    rec(s + chars[m], m + 1);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    rec("a", 1);
}
