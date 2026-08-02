#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if (n < 2 * m) {
        cout << "NO\n";
        return;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool possible = true;
    for (int i = 0; i < m; i++) {
        if (a[i] > b[i] || a[n - m + i] < b[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}