#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end();

void solve() {
    int n;
    cin >> n;
    vi a(n), c(n);
    set<int> b;
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    int cnt = 0;
    bool y = true;
    for (int i = 0; i < n; i++) {
        auto it = b.lower_bound(a[i]);
        if (it == b.end()) {
            y = false;
            break;
        }
        c[i] = *it;
        b.erase(it);
    }
    if (!y) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (c[i] > c[j]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}