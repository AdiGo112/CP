#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end();

void solve() {
    int n;
    long long d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> pref(3 * n + 1, 0);
    for (int i = 0; i < 3 * n; i++) {
        pref[i + 1] = pref[i] + a[i % n];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int c = i + n;
        long long win = pref[c + d + 1] - pref[c - d];
        long long s = win - a[i];

        long long g = 2 * d * a[i] - s;
        if (g > 0) {
            ans += g;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}