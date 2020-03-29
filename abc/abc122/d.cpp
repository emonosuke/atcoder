#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

// AGC, GAC, ACG, A?GC, AG?C is invalid, otherwise valid
bool isvalid(string last3, string l0){
    if(last3 == "AGC" || last3 == "GAC" || last3 == "ACG") return false;
    if(last3.substr(1, 2) + l0 == "AGC") return false;
    if(last3.substr(1, 2) + l0 == "GAC") return false;
    if(last3.substr(1, 2) + l0 == "ACG") return false;
    if(last3.substr(0, 1) == "A" && (last3.substr(2, 1) + l0) == "GC") return false;
    if(last3.substr(0, 2) == "AG" && l0 == "C") return false;
    return true;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    vector<string> c = {"A", "C", "G", "T"};
    unordered_map<string, ll> pdp;
    unordered_map<string, ll> dp;

    pdp["TTT"] = 1;

    for(int i=0;i<n;i++){
        for(string l3: c){
            for(string l2: c){
                for(string l1: c){
                    string last3 = l3 + l2 + l1;
                    for(string l0: c){
                        if(isvalid(last3, l0)){
                            string newlast3 = l2 + l1 + l0;
                            dp[newlast3] += pdp[last3];
                            dp[newlast3] %= MOD;
                        }
                    }
                }
            }
        }
        pdp = dp;
        dp = unordered_map<string, ll>();
    }
    ll ans = 0;
    for(string l3: c){
        for(string l2: c){
            for(string l1: c){
                string last3 = l3 + l2 + l1;
                ans += pdp[last3];
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}
