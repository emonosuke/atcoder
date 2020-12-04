#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const int MAX_H = 1500;
int H, W;
vector<vector<char>> board(MAX_H, vector<char>(MAX_H));
vector<vector<bool>> lighted(MAX_H, vector<bool>(MAX_H));
bool inlight = false;

void check_light(int i, int j)
{
    if (board[i][j] == 'L')
    {
        lighted[i][j] = true;
        inlight = true;
    }
    else if (board[i][j] == 'B')
    {
        lighted[i][j] = false;
        inlight = false;
    }
    else if (inlight)
    {
        lighted[i][j] = true;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int h, w, n, m;
    cin >> H >> W >> n >> m;
    for (int i = 0; i < H; i++)
        fill(board[i].begin(), board[i].end(), 'N');
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 'L';
    }
    for (int i = 0; i < m; i++)
    {
        int c, d;
        cin >> c >> d;
        board[c - 1][d - 1] = 'B';
    }

    // left to right
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            check_light(i, j);
        inlight = false;
    }
    // right to left
    for (int i = 0; i < H; i++)
    {
        for (int j = W - 1; j >= 0; j--)
            check_light(i, j);
        inlight = false;
    }
    // upper to lower
    for (int j = 0; j < W; j++)
    {
        for (int i = 0; i < H; i++)
            check_light(i, j);
        inlight = false;
    }
    // lower to upper
    for (int j = 0; j < W; j++)
    {
        for (int i = H - 1; i >= 0; i--)
            check_light(i, j);
        inlight = false;
    }
    int ans = 0;
    // count
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            if (lighted[i][j])
                ans++;
    }
    cout << ans << endl;
}
