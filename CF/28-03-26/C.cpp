#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    if (k == n) {
        vector<bool> used(n + 1, false);
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                if (used[b[i]]) {
                    cout << "NO\n";
                    return;
                }
                used[b[i]] = true;
            }
        }
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < n - k; i++) {
        if (b[i] != -1 && b[i] != a[i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = k; i < n; i++) {
        if (b[i] != -1 && b[i] != a[i]) {
            cout << "NO\n";
            return;
        }
    }

    if (n < 2 * k) {
        unordered_set<int> aFree, bUsed;
        for (int i = n - k; i < k; i++) aFree.insert(a[i]);
        for (int i = n - k; i < k; i++) {
            if (b[i] != -1) {
                if (bUsed.count(b[i]) || !aFree.count(b[i])) {
                    cout << "NO\n";
                    return;
                }
                bUsed.insert(b[i]);
            }
        }
    }

    cout << "YES\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
//coding