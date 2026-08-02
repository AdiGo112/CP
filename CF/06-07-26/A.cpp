#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 2) cnt += a[i];
    }
    if (cnt >= 3) {
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