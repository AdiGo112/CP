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
    vi a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + b[i];

    vector<ll> cnt(n + 2, 0);
    vector<ll> extra(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        ll need = a[i] + pref[i - 1];
        int j = upper_bound(pref.begin(), pref.end(), need) - pref.begin();
        cnt[i]++;
        cnt[j]--;
        ll used = pref[j - 1] - pref[i - 1];
        extra[j] += a[i] - used;
    }
    ll active = 0;
    for (int i = 1; i <= n; i++) {
        active += cnt[i];
        cout << active * b[i] + extra[i] << " ";
    }
    cout << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}