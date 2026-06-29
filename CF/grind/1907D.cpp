#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
bool possible(ll mid, const vector<ll> &l, const vector<ll> &r) {
    ll L = 0, R = 0;
    for(int i = 0; i < l.size(); i++){
        L -= mid;
        R += mid;

        L = max(L, l[i]);
        R = min(R, r[i]);
        if(L > R) return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    
    ll L = 0, R = 1e9;
    while(L < R){
        ll mid = L + (R - L) / 2;
        if(possible(mid, l, r)){
            R = mid;
        }
        else{
            L = mid + 1;
        }
    }
    cout << L << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}