#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k = 0;
    for (int i = 0; i + 1 < n; i++) k = max(k, a[i] - a[i + 1]);

    bool can0 = true;
    bool can1 = true;

    for (int i = 0; i + 1 < n; i++) {
        bool n0 = false, n1 = false;
        if (can0) {
            if (a[i] <= a[i + 1]) n0 = true;
            if (a[i] <= a[i + 1] + k) n1 = true;
        }
        if (can1) {
            if (a[i] + k <= a[i + 1]) n0 = true;
            if (a[i] + k <= a[i + 1] + k) n1 = true;
        }
        can0 = n0;
        can1 = n1;
    }
    cout << ((can0 || can1) ? "YES\n" : "NO\n");
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}