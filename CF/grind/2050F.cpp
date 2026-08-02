#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

const int MAXN = 200005;
const int LOG = 19;

int st_max[MAXN][LOG];
int st_gcd[MAXN][LOG];

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }

    vi mod(n - 1);
    for (int i = 0; i < n - 1; i++) {
        mod[i] = abs(a[i] - a[i + 1]);
    }

    int cur_log = __lg(n) + 1;

    for (int i = 0; i < n; i++) st_max[i][0] = a[i];
    for (int i = 0; i < n - 1; i++) st_gcd[i][0] = mod[i];

    for (int j = 1; j < cur_log; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
        }
        for (int i = 0; i + (1 << j) <= n - 1; i++) {
            st_gcd[i][j] = std::gcd(st_gcd[i][j - 1], st_gcd[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l == r) {
            cout << 0 << " ";
            continue;
        }

        int len_max = r - l + 1;
        int k_max = __lg(len_max);
        int mx1 = max(st_max[l][k_max], st_max[r - (1 << k_max) + 1][k_max]);

        int len_gcd = (r - 1) - l + 1;
        int k_gcd = __lg(len_gcd);
        int g = std::gcd(st_gcd[l][k_gcd], st_gcd[(r - 1) - (1 << k_gcd) + 1][k_gcd]);

        if (g == mx1) {
            cout << 0 << " ";
        } else {
            cout << g << " ";
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O is crucial here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
}