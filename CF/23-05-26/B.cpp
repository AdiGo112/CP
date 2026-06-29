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
    vi a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    ll ans = 0;
    int best = 0;
    for (int i = 0; i < n; i++) {
        ans += max(a[i], b[i]);
        best = max(best, min(a[i], b[i]));
    }
    ans += best;
    cout << ans << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}