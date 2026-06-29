#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(auto &a:a) cin >> a;
    int mn = INT_MAX;
    int sum = 0;
    for(int i=0; i<n; i++){
        mn = min(mn, a[i]);
        sum += mn;
    }
    cout << sum <<'\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}