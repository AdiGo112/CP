#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi pre1(n), pre2(n), pre3(n);

    for (int i = 0; i < n; i++) {
        if (i) {
            pre1[i] = pre1[i - 1];
            pre2[i] = pre2[i - 1];
            pre3[i] = pre3[i - 1];
        }

        if (a[i] == 1)
            pre1[i]++;
        else if (a[i] == 2)
            pre2[i]++;
        else
            pre3[i]++;
    }

    vi val(n);
    vector<bool> goodLeft(n);

    for (int i = 0; i < n; i++) {
        goodLeft[i] = (pre1[i] >= pre2[i] + pre3[i]);
        val[i] = pre1[i] + pre2[i] - pre3[i];
    }

    const int INF = 1e9;
    int best = INF;

    for (int j = 1; j <= n - 2; j++) {
        int i = j - 1;

        if (goodLeft[i]) best = min(best, val[i]);

        if (best != INF && val[j] >= best) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}