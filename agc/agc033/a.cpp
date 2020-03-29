#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int h, w; cin >> h >> w;
    vector<string> a(h);
    for(int i=0;i<h;i++) cin >> a[i];
    queue<tuple<int, int, int> > Q;  // (i, j, level)
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j] == '#'){
                Q.push(make_tuple(i, j, 0));
            }
        }
    }
    int ans = 0;
    while(!Q.empty()){
        tuple<int, int, int> t = Q.front(); Q.pop();
        int i = get<0>(t), j = get<1>(t), level = get<2>(t);
        // cout << i << " " << j << " " << level << endl;
        ans = level;
        for(int k=0;k<4;k++){
            if(i + dx[k] < 0 || i + dx[k] >= h || j + dy[k] < 0 || j + dy[k] >= w){
                continue;
            }
            if(a[i + dx[k]][j + dy[k]] == '.'){
                // cout << i + dx[k] << " " << j + dy[k] << endl;
                a[i + dx[k]][j + dy[k]] = '#';
                Q.push(make_tuple(i + dx[k], j + dy[k], level + 1));
            }
        }
    }
    cout << ans << endl;
}
