#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vi c;
    for (auto const& [val, count] : freq) c.push_back(count);
    sort(all(c));
    int m = c.size();
    vi suff(m + 1, 0);
    for (int i = m - 1; i >= 0; i--) suff[i] = suff[i + 1] + c[i];

    int ans = 0;
    for (int e = 0; e < m; e++) {
        if (e > 0 && c[e - 1] == c[e]) continue;
        int s = m - e;
        int maxDrop = c[e] - 1;
        int minLen = suff[e] - s * maxDrop;
        if (k >= minLen && (k - minLen) % s == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}