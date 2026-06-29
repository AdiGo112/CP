#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end();

const int MOD = 998244353;
ll modpow(ll a, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}
void solve() {
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    ll d = (r - 1) * m + (c - 1) * n - (r - 1) * (c - 1);
    cout << modpow(2, d) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}