#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
struct BIT {
    int n; vector<int> t;
    BIT(int n) : n(n), t(n+1, 0) {}
    void upd(int i, int v) { for (i++; i <= n; i += i&-i) t[i] += v; }
    int qry(int i) { int s=0; for (i++; i>0; i -= i&-i) s += t[i]; return s; }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    
    vector<ll> Q(n+1); Q[0] = 0;
    for (int i = 1; i <= n; i++)
        Q[i] = Q[i-1] + (i%2==1 ? a[i-1] : -a[i-1]);
    
    vector<ll> sq = Q;
    sort(sq.begin(), sq.end());
    sq.erase(unique(sq.begin(), sq.end()), sq.end());
    int m = sq.size();
    auto compress = [&](ll v) {
        return (int)(lower_bound(sq.begin(), sq.end(), v) - sq.begin());
    };
    
    BIT even_bit(m), odd_bit(m);
    ll ans = 0;
    even_bit.upd(compress(Q[0]), 1);
    
    for (int j = 1; j <= n; j++) {
        int cj = compress(Q[j]);
        if (j % 2 == 1) {
            if (cj > 0) ans += even_bit.qry(cj - 1);
            odd_bit.upd(cj, 1);
        } else {
            ans += odd_bit.qry(m-1) - odd_bit.qry(cj);
            even_bit.upd(cj, 1);
        }
    }
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