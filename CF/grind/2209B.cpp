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
    vi ans(n);
    for (int i = 0; i < n; i++) {
        int mn = 0, mx = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                mn++;
            else if (a[j] > a[i])
                mx++;
        }
        ans[i] = max(mn, mx);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}