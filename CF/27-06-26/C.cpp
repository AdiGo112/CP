#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end();

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s ^= a[i];
        if (a[i] > 0) c++;
    }

    if (c <= 1) {
        cout << 0 << "\n";
        return;
    }
    
    ll ans = 0;
    if (s == 0) {
        ans++;
    }
    for (int i = 0; i < n; ++i) {
        if ((s ^ a[i]) < a[i]) {
            ans++;
        }
    }
    
    cout << ans % 998244353 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}