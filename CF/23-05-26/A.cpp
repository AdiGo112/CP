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
    int mn = 1001;
    int mx = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    cout << (mx - mn + 1) / 2 << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}