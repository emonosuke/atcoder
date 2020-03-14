#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};
const int SZ = 100000;
const int OFS = 50000;

bool ab[SZ], ac[SZ], bc[SZ];

bool match(char c1, char c2){
    return (c1 == '?' || c2 == '?' || c1 == c2);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string a, b, c; cin >> a >> b >> c;
    int na = a.size(), nb = b.size(), nc = c.size();
    fill(ab, ab + SZ, true);
    fill(ac, ac + SZ, true);
    fill(bc, bc + SZ, true);
    for(int i=0;i<na;i++) for(int j=0;j<nb;j++) if(!match(a[i], b[j])) ab[i-j+OFS] = false;
    for(int i=0;i<na;i++) for(int j=0;j<nc;j++) if(!match(a[i], c[j])) ac[i-j+OFS] = false;
    for(int i=0;i<nb;i++) for(int j=0;j<nc;j++) if(!match(b[i], c[j])) bc[i-j+OFS] = false;

    int ans = na + nb + nc;
    for(int i=-4000;i<=4000;i++){
        for(int j=-4000;j<=4000;j++){
            if(ab[i+OFS] && ac[j+OFS] && bc[j-i+OFS]){
                int left = min(0, min(i, j));
                int right = max(na, max(nb + i, nc + j));
                ans = min(ans, right - left);
            }
        }
    }
    cout << ans << endl;
}
