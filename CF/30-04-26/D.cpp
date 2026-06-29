#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
int getMex(vector<bool>& seen) {
    int mex = 0;
    while (mex < seen.size() && seen[mex]) mex++;
    return mex;
}
int caseBoth(vi& a, int l, int r, int n) {
    int L = l, R = r;
    while (L < R) {
        if (a[L] != a[R]) return 0;
        L++;
        R--;
    }
    while (l > 0 && r < 2 * n - 1 && a[l - 1] == a[r + 1]) {
        l--;
        r++;
    }
    vector<bool> seen(n, false);
    for (int i = l; i <= r; i++) {
        seen[a[i]] = true;
    }
    return getMex(seen);
}
int caseCenter(vi& a, int idx, int n) {
    int L = idx, R = idx;
    vector<bool> seen(n, false);
    while (L >= 0 && R < 2 * n && a[L] == a[R]) {
        seen[a[L]] = true;
        seen[a[R]] = true;
        L--;
        R++;
    }
    return getMex(seen);
}

void solve() {
    int n;
    cin >> n;
    vi a(2 * n);
    vector<vi> pos(n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int l = pos[0][0];
    int r = pos[0][1];

    int ans = 0;
    ans = max(ans, caseBoth(a, l, r, n));
    ans = max(ans, caseCenter(a, l, n));
    ans = max(ans, caseCenter(a, r, n));

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