#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
bool check(int V, const vi& a, const vi& b, int n) {
    int ones = 0;
    int blocks = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int x = 0;
        if (a[i] >= V && b[i] >= V) {
            x = 1;
        } else if (a[i] < V && b[i] < V) {
            x = -1;
        } else {
            x = 0;
        }
        if (x == 1) {
            ones++;
            ok = false;
        } else if (x == -1) {
            if (!ok) {
                blocks++;
                ok = true;
            }
        }
    }
    return (ones - blocks) >= 1;
}
void solve() {
    int n;
    cin >> n;

    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int low = 1, high = 2 * n, ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, a, b, n)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}