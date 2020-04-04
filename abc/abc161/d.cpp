#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const int DEPTH = 11;
vector<ll> ans;

bool check(vector<int> v, int i, bool lz){
    if(lz) return true;
    if(i == v.back() || (i + 1) == v.back() || (i - 1) == v.back()) return true;
    return false;
}

void dfs(vector<int> v, bool lz){
    if(int(v.size()) >= DEPTH){
        ll res = std::accumulate(v.begin(), v.end(), 0LL, [](ll acc, ll val){
            return 10LL * ll(acc) + ll(val);
        });
        ans.push_back(res);
        return;
    }
    for(int i=0;i<=9;i++){
        if(check(v, i, lz)){
            v.push_back(i);
            if(lz && i == 0) dfs(v, true);
            else dfs(v, false);
            v.pop_back();
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll k; cin >> k;
    vector<int> s = {0};
    dfs(s, true);
    // cout << ans.size() << endl;
    cout << ans[k] << endl;
}
