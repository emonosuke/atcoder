#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    // 0101...
    bool zero = true;
    int cnt0 = 0, cnt1 = 0;
    for(char c: s){
        if(zero && (c == '1')) cnt0++;
        if(!zero && (c == '0')) cnt0++;
        zero = !zero;
    }
    // 1010...
    zero = false;
    for(char c: s){
        if(zero && (c == '1')) cnt1++;
        if(!zero && (c == '0')) cnt1++;
        zero = !zero;
    }
    cout << min(cnt0, cnt1) << endl;
}
