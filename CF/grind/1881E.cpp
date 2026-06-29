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
    for (int &x : a) cin >> x;
    vi dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1 + dp[i + 1];
        if (i + a[i] < n) {
            dp[i] = min(dp[i], dp[i + a[i] + 1]);
        }
    }
    cout << dp[0] << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}