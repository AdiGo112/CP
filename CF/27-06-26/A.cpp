#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end();

void solve() {
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    for (ll cost = 1; cost <= n; cost <<= 1) {
        ll take = min(k, n / cost);
        ans += take;
        n -= take * cost;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}