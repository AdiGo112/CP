#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    int len = 2 * n;
    vi a(len + 1);
    vi first(n + 1, 0);
    vector<ll> dp(len + 1, 0);

    for (int i = 1; i <= len; ++i) {
        cin >> a[i];
        dp[i] = dp[i - 1];

        if (first[a[i]] == 0) {
            first[a[i]] = i;
        } else {
            int j = first[a[i]];
            ll L = i - j + 1;
            ll gain = L * L - L;

            dp[i] = max(dp[i], dp[j - 1] + gain);
        }
    }
    cout << dp[len] + len << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}