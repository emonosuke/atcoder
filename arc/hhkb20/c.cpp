#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXP = 200000;
const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<bool> used(MAXP + 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        used[p[i]] = true;
        if (used[ans])
        {
            for (int j = ans + 1; j <= MAXP; j++)
            {
                if (!used[j])
                {
                    ans = j;
                    cout << ans << endl;
                    break;
                }
            }
        }
        else
        {
            cout << ans << endl;
        }
    }
}
