#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
ll INF = 1e18;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    bool possible = true;

    // Check if the prefix maximum array is validly non-decreasing
    for (int i = 1; i < n; i++) {
        if (c[i] < c[i - 1]) {
            possible = false;
        }
    }

    if (!possible) {
        cout << "No\n";
        return;
    }

    vector<ll> U(n), E(n, INF);
    for (int i = 0; i < n; i++) {
        U[i] = c[i];
        if (i == 0) {
            E[i] = c[i];
        } else {
            if (c[i] > c[i - 1]) {
                E[i] = c[i];
            }
        }
    }

    // Step 1: Backward propagation of ranges & exact matches
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '1') {
            if (E[i] != INF) {
                ll req = E[i] - a[i];
                if (E[i - 1] != INF && E[i - 1] != req) {
                    possible = false;
                    break;
                }
                E[i - 1] = req;
            }
            U[i - 1] = min(U[i - 1], U[i] - a[i]);
        }
    }

    if (!possible) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (E[i] != INF && E[i] > U[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "No\n";
        return;
    }

    vector<ll> ans_a(n);
    ll last_b = 0;

    // Step 2: Forward construction
    for (int i = 0; i < n; i++) {
        ll b_i;
        if (i == 0) {
            b_i = c[0];
            if (s[0] == '1' && a[0] != c[0]) {
                possible = false;
                break;
            }
            ans_a[0] = c[0];
        } else {
            if (s[i] == '1') {
                b_i = last_b + a[i];
                if (E[i] != INF && b_i != E[i]) {
                    possible = false;
                    break;
                }
                if (b_i > U[i]) {
                    possible = false;
                    break;
                }
                ans_a[i] = a[i];
            } else {
                b_i = (E[i] != INF) ? E[i] : U[i];
                ans_a[i] = b_i - last_b;
            }
        }
        last_b = b_i;
    }

    if (!possible) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << ans_a[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}