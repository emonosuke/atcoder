#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string S; cin >> S;
    int q; cin >> q;
    bool rev = false;
    list<char> chars(S.begin(), S.end());
    for(int i=0;i<q;i++){
        int t; cin >> t;
        if(t == 1){
            rev = !rev;
        }else{
            int f; char c;
            cin >> f >> c;
            if(rev){
                if(f == 1){
                    chars.push_back(c);
                }else{
                    chars.push_front(c);
                }
            }else{
                if(f == 1){
                    chars.push_front(c);
                }else{
                    chars.push_back(c);
                }
            }
        }
    }
    if(rev){
        reverse(chars.begin(), chars.end());
    }
    for(char c: chars){
        cout << c;
    }
    cout << endl;
}
