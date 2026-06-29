#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    // pre[i] = sum of abs values from 0 to i
    vector<long long> pre(n);

    pre[0] = abs(a[0]);

    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + abs(a[i]);
    }

    // suf[i] = normal suffix sum
    vector<long long> suf(n + 1, 0);

    suf[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }

    // best = no operation initially
    long long best = suf[0];

    int idx = -1;

    // choose best final operation index
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) continue;

        long long left = (i == 0 ? 0 : pre[i - 1]);
        long long right = (i == n - 1 ? 0 : suf[i + 1]);

        long long score = left - a[i] + right;

        if (score > best) {
            best = score;
            idx = i;
        }
    }

    // no operation is better
    if (idx == -1) {
        cout << 0 << '\n';
        return;
    }

    vector<int> ops;

    // build operations backwards
    for (int i = idx - 1; i >= 0; i--) {
        // odd flips already happened
        if (ops.size() & 1) a[i] = -a[i];

        // if currently positive,
        // flip prefix here
        if (a[i] > 0) ops.push_back(i);
    }

    // final operation
    ops.push_back(idx);

    cout << ops.size() << '\n';

    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i] + 1 << " \n"[i + 1 == ops.size()];
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