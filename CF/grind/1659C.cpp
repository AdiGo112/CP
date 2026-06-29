#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;

    vector<ll> a(n + 1), pref(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    ll ans = 1e18;
    ll s = 0;

    for (int i = 0; i <= n; i++) {
        // s = total conquered distance while shifting capital
        if (i) s += a[i] - a[i - 1];

        ll moveCost = x * a[i];

        ll attackCost = y * (pref[n] - pref[i] - a[i] * (n - i) + s);

        ans = min(ans, moveCost + attackCost);
    }

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