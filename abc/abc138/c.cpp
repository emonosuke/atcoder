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
    priority_queue<double, vector<double>, greater<double>> pq;
    for (int i = 0; i < n; i++)
    {
        double v;
        cin >> v;
        pq.push(v);
    }
    while (pq.size() >= 2)
    {
        double x = pq.top();
        pq.pop();
        double y = pq.top();
        pq.pop();
        pq.push((x + y) / 2.0);
    }
    cout << fixed << setprecision(12) << pq.top() << endl;
}
