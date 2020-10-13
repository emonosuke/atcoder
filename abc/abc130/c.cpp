#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int w, h, x, y;
    cin >> w >> h >> x >> y;
    double half = (double(w) * double(h)) / 2.0;
    int center = int((x * 2 == w && y * 2 == h));
    cout << fixed << setprecision(9) << half << " ";
    cout << center << endl;
}
