#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int x, y, z; cin >> x >> y >> z;
    int tmp = x;
    x = y;
    y = tmp;
    tmp = x;
    x = z;
    z = tmp;
    cout << x << " " << y << " " << z << endl;
}
