#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end();

void solve() {
    int n;
    cin >> n;

    vi p(n + 1);
    vi depth(n + 1, 0);
    vi mx(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        depth[i] = depth[p[i]] + 1;
    }

    for (int i = 1; i <= n; i++) {
        mx[i] = depth[i];
    }

    for (int i = n; i >= 2; i--) {
        mx[p[i]] = max(mx[p[i]], mx[i]);
    }

    vi max1(n + 1, -1);
    vi max2(n + 1, -1);

    for (int i = 2; i <= n; i++) {
        int parent = p[i];
        int val = mx[i];

        if (val > max1[parent]) {
            max2[parent] = max1[parent];
            max1[parent] = val;
        } else if (val > max2[parent]) {
            max2[parent] = val;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (max2[i] != -1) {
            ans += max2[i] - depth[i] + 1;
        } else {
            ans += 1;
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