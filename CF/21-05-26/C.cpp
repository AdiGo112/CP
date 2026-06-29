#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int& x : a) cin >> x;

    vector<pair<int, ll>> pairs;
    pairs.reserve(n * 64);

    for (int x : a) {
        ll cost = 0;
        int v = x;
        while (v > 2) {
            pairs.push_back({v, cost});
            if (v % 2 == 0)
                v /= 2;
            else
                v++;
            cost++;
        }
        pairs.push_back({v, cost});
        pairs.push_back({3 - v, cost + 1});  // 3-1=2, 3-2=1
    }

    sort(all(pairs));

    ll ans = LLONG_MAX;
    for (int i = 0; i < (int)pairs.size();) {
        int j = i, val = pairs[i].first;
        ll sum = 0;
        int cnt = 0;
        while (j < (int)pairs.size() && pairs[j].first == val) 
            sum += pairs[j].second, cnt++, j++;
        if (cnt == n) ans = min(ans, sum);
        i = j;
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