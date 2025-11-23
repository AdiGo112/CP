#include <bits/stdc++.h>
using namespace std;

// ----------------- MACROS -----------------
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(x) ((int)(x.size()))
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pii>
#define forn(i,n) for(int i=0;i<(n);i++)

// ---------------- FAST I/O ----------------
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

// --------------- DEBUGGING ---------------
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// --------------- COMMON FUNCTIONS ---------------
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

// ----------------- SOLVE FUNCTION -----------------
const int NEG = (int)-4e18;
struct SegTree {
    int n;
    vector<int> st;
    SegTree() {}
    SegTree(const vector<int>& a) { build(a); }
    void build(const vector<int>& a) {
        n = (int)a.size();
        st.assign(4*n, NEG);
        build_rec(1, 0, n-1, a);
    }
    void build_rec(int p, int l, int r, const vector<int>& a) {
        if (l == r) { st[p] = a[l]; return; }
        int mid = (l + r) >> 1;
        build_rec(p<<1, l, mid, a);
        build_rec(p<<1|1, mid+1, r, a);
        st[p] = max(st[p<<1], st[p<<1|1]);
    }
    int query(int L, int R) { 
        if (L > R) return NEG;
        return query_rec(1, 0, n-1, L, R);
    }
    int query_rec(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) return st[p];
        int mid = (l + r) >> 1;
        int ans = NEG;
        if (L <= mid) ans = max(ans, query_rec(p<<1, l, mid, L, R));
        if (R > mid)  ans = max(ans, query_rec(p<<1|1, mid+1, r, L, R));
        return ans;
    }
};
void solve() {        
    int n;
        int l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + a[i];

        int N = n + 1;
        vector<int> g(N), h(N);
        for (int k = 0; k <= n; ++k) {
            g[k] = (int)k * l - pref[k];
            h[k] = (int)k * r - pref[k];
        }

        SegTree sg_g(g), sg_h(h);

        int ans = 0;
        for (int m = 0; m <= n; ++m) {
            int sum_last_m = (m == 0 ? 0 : pref[n] - pref[n - m]);
            int limit = n - m;
            if (m <= limit) {
                int L = m;
                int R = limit;
                int maxg = sg_g.query(L, R);
                if (maxg != NEG) {
                    int cand1 = maxg + (sum_last_m - (int)m * l);
                    ans = max(ans, cand1);
                }
            }
            {
                int upto = min(m, limit);
                if (upto >= 0) {
                    int maxh = sg_h.query(0, upto);
                    if (maxh != NEG) {
                        int cand2 = maxh + (sum_last_m - (int)m * r);
                        ans = max(ans, cand2);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
