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
    int x, n;
    cin >> x >> n;
    if (n == 0)
    {
        cout << x << endl;
        return 0;
    }
    vector<bool> used(201);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        used[p] = true;
    }
    for (int d = 0; d <= 100; d++)
    {
        if (!used[x - d])
        {
            cout << x - d << endl;
            return 0;
        }
        if (!used[x + d])
        {
            cout << x + d << endl;
            return 0;
        }
    }
}
