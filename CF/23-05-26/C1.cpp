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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vi ops;
    int flip = 0;
    for (int i = n; i >= 1; i--) {
        ll cur = a[i];
        if (flip % 2) {
            cur = -cur;
        }
        if (cur > 0) {
            ops.push_back(i);
            flip ^= 1;
        }
    }
    cout << ops.size() << '\n';
    for (int x : ops) {
        cout << x << ' ';
    }
    cout << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}