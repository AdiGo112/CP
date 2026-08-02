#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;

ll power(ll b, ll e) {
    ll res = 1;
    b %= MOD;
    while (e > 0) {
        if (e % 2 == 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    vi p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1)
            cnt++;
        else
            p.push_back(x);
    }
    if (p.empty()) {
        cout << (cnt > 0 ? power(2, cnt - 1) : 1) << "\n";
        return;
    }

    int unique = 1;
    int diff = 0;

    for (int i = 1; i < (int)p.size(); i++) {
        if (p[i] != p[i - 1]) {
            unique++;
            if (p[i] == p[i - 1] + 1) {
                diff++;
            }
        }
    }

    ll W = power(2, p.size() - unique);

    if (cnt == 0) {
        cout << W << "\n";
    } else {
        ll parity = power(2, cnt - 1);
        ll caseA = (parity * W) % MOD;
        ll caseB = ((parity * W) % MOD * diff) % MOD;

        cout << (caseA + caseB) % MOD << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}