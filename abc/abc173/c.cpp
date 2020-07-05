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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h, vector<char>(w));
    int sumblack = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
                sumblack++;
        }
    }
    // cout << sumblack << endl;
    // black
    vector<int> sumH(h), sumW(w);
    for (int i = 0; i < h; i++)
    {
        sumH[i] = 0;
        for (int j = 0; j < w; j++)
            if (c[i][j] == '#')
                sumH[i]++;
    }
    for (int j = 0; j < w; j++)
    {
        sumW[j] = 0;
        for (int i = 0; i < h; i++)
            if (c[i][j] == '#')
                sumW[j]++;
    }
    int ans = 0;
    for (int bitH = 0; bitH < (1 << h); bitH++)
    {
        for (int bitW = 0; bitW < (1 << w); bitW++)
        {
            int rmblack = 0;
            for (int i = 0; i < h; i++)
            {
                if (bitH & (1 << i))
                {
                    rmblack += sumH[i];
                }
            }
            for (int j = 0; j < w; j++)
            {
                if (bitW & (1 << j))
                {
                    rmblack += sumW[j];
                    for (int i = 0; i < h; i++)
                    {
                        if (bitH & (1 << i))
                        {
                            // overlap
                            if (c[i][j] == '#')
                                rmblack--;
                        }
                    }
                }
            }
            if (sumblack - rmblack == k)
                ans++;
        }
    }
    cout << ans << endl;
}
