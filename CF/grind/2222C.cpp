#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
const int N = 5e3 + 10;
int n, a[N], b[N], mid, dp[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memcpy(b + 1, a + 1, n << 2);
    sort(b + 1, b + n + 1);
    mid = b[(n + 1) >> 1];
    for (int i = 1; i <= n; i++) {
        if (a[i] == mid) {
            a[i] = 0;
            continue;
        }
        a[i] = (a[i] > mid ? 1 : -1);
    }
    for (int i = 1, flg = 0; i <= n; i++) {
        dp[i] = 0;
        flg = !a[i];
        if (flg and (i == 1 or dp[i - 1])) dp[i] = dp[i - 1] + 1;
        for (int j = i - 3, sm = a[i]; j >= 0; j -= 2) {
            flg += !a[j + 1];
            flg += !a[j + 2];
            sm += a[j + 1] + a[j + 2];
            if (abs(sm) >= flg or (j and !dp[j])) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n] << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}