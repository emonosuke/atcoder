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
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    h[0] = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (h[i - 1] > h[i])
        {
            ok = false;
            break;
        }
        else if (h[i - 1] != h[i])
        {
            h[i]--;
        }
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
