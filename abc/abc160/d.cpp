#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, x, y; cin >> n >> x >> y;
    x--;
    y--;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dist = min(abs(x - i) + 1 + abs(y - j), j - i);
            ans[dist]++;
        }
    }
    for(int i=1;i<n;i++){
        cout << ans[i] << endl;
    }
}
