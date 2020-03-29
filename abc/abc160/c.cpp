#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int k, n; cin >> k >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    int maxd = 0;
    for(int i=0;i<n-1;i++){
        maxd = max(a[i+1] - a[i], maxd);
    }
    maxd = max(a[0] + (k - a[n-1]), maxd);
    cout << k - maxd << endl;
}
