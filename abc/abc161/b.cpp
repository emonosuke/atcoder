#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    int cnt = 0;
    int th;
    if(sum % 4*m == 0) th = sum / (4*m);
    else th = (sum / (4*m)) + 1;
    for(int i=0;i<n;i++){
        if(a[i] >= th) cnt++;
    }
    if(cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
}
