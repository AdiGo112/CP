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

    ll cnt = 0;
    int curMin = a[n - 1];
    int curSize = 1;
    int maxSize = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= curMin) {
            cnt += (a[i] - curMin);
            curSize++;
            maxSize = max(maxSize, curSize);
        } else {
            curMin = a[i];
            curSize = 1;
        }
    }

    ll maxCnt = cnt + maxSize - 1;
    cout << maxCnt << "\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}