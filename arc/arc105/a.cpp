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
    vector<ll> a(4);
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    for (int i = 1; i < (1 << 4) - 1; i++)
    {
        ll sumx = 0, sumy = 0;
        for (int j = 0; j < 4; j++)
        {
            if ((i >> j) & 1)
            {
                //cout << "select: " << a[j] << endl;
                sumx += a[j];
            }
            else
            {
                //cout << "not select: " << a[j] << endl;
                sumy += a[j];
            }
        }
        //cout << sumx << " " << sumy << endl;
        if (sumx == sumy)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
