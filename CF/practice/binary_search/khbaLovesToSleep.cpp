#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()

//==================== SOLVE ======================//
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vi a(n);
    for (auto& e : a) cin >> e;

    a.push_back(1e9);
    a.push_back(-1e9);
    n += 2;
    sort(all(a));
    int l = 0, r = x + 1;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        a[0] = -m;
        a[n - 1] = x + m;
        int cnt = 0;
        for (int i = 1; i < n; i++) cnt += max(0, (a[i] - m) - (a[i - 1] + m) + 1);
        if (cnt >= k)
            l = m;
        else
            r = m;
    }
    a[0] = -l;
    a[n - 1] = x + l;
    int j = 0;
    for (int i = 1; i < n; i++)
        for (j = max(j, a[i - 1] + l); j <= min(a[i] - l, x) && k; j++) cout << j << " ", k--;
    cout << "\n";
}

//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) solve();
}