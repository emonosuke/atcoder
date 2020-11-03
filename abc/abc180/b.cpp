#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    double m, u, c = 0;
    for (int i = 0; i < n; i++)
    {
        m += abs(x[i]);
        u += abs(x[i]) * abs(x[i]);
        c = max(c, abs(x[i]));
    }
    cout << fixed << setprecision(12) << m << endl;
    cout << fixed << setprecision(12) << sqrt(u) << endl;
    cout << fixed << setprecision(12) << c << endl;
}
