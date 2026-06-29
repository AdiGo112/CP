#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<ll> cnt(3, 0);
    cnt[0] = 1;

    int pref = 0;
    ll ans = 0;

    int alt = 1;

    for (int i = 0; i < n; i++) {
        pref += (s[i] == '1' ? 1 : -1);
        pref %= 3;
        if(pref < 0) pref += 3;

        ll total = cnt[0] + cnt[1] + cnt[2];

        ans += total - cnt[pref];

        if (i > 0) {
            if (s[i] != s[i - 1]) alt++;
            else alt = 1;
        }

        ans -= (alt - 1) / 2;

        cnt[pref]++;
    }

    cout << ans << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}