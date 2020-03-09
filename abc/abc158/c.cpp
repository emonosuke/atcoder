#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    double a, b; cin >> a >> b;
    double amin = a / 0.08;
    double amax = (a + 1) / 0.08;
    double bmin = b / 0.1;
    double bmax = (b + 1) / 0.1;
    if(amax <= bmin || bmax <= amin){
        cout << -1 << endl;
    }else if(amin <= bmin){
        if(ceil(bmin) < min(amax, bmax)){
            cout << ceil(bmin) << endl;
        }else{
            cout << -1 << endl;
        }
    }else if(bmin <= amin){
        if(ceil(amin) < min(amax, bmax)){
            cout << ceil(amin) << endl;
        }else{
            cout << -1 << endl;
        }
    }
}
