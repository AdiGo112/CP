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
void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    struct Query { int c, l, r; };
    vector<Query> qs(q);
    for (int i = 0; i < q; ++i) cin >> qs[i].c >> qs[i].l >> qs[i].r;

    vector<int> diff1(n+3, 0), diff2(n+3, 0);
    for (auto &Q : qs) {
        if (Q.c == 1) {
            diff1[Q.l] += 1;
            diff1[Q.r + 1] -= 1;
        } else {
            diff2[Q.l] += 1;
            diff2[Q.r + 1] -= 1;
        }
    }

    vector<int> in_c1(n+1, 0), in_c2(n+1, 0);

    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff1[i];
        in_c1[i] = (cur > 0);
    }
    cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff2[i];
        in_c2[i] = (cur > 0);
    }

    vector<int> a(n+1, -1);

    set<int> avail_for_c2;
    for (int i = 1; i <= n; ++i) if (!in_c1[i]) avail_for_c2.insert(i);

    vector<Query> c2s;
    for (auto &Q : qs) if (Q.c == 2) c2s.push_back(Q);


    for (auto &Q : c2s) {
        int l = Q.l, r = Q.r;
        vector<int> picked;

        auto it = avail_for_c2.lower_bound(l);
        while ((int)picked.size() < k && it != avail_for_c2.end() && *it <= r) {
            picked.push_back(*it);
            it = next(it);
        }

        for (int i = 0; i < k; ++i) {
            int pos = picked[i];
            a[pos] = i;
            avail_for_c2.erase(pos);
        }
    }

    set<int> avail_for_k;
    for (int i = 1; i <= n; ++i) {
        if (!in_c2[i] && a[i] == -1) avail_for_k.insert(i);
    }

    for (auto &Q : qs) {
        if (Q.c != 1) continue;
        int l = Q.l, r = Q.r;

        bool hasK = false;
        for (int pos = l; pos <= r; ++pos) {
            if (a[pos] == k) { hasK = true; break; }
        }
        if (hasK) continue;

        auto it = avail_for_k.lower_bound(l);
        if (it == avail_for_k.end() || *it > r) {
            cout << -1 << "\n";
            return;
        }

        int pos = *it;
        a[pos] = k;
        avail_for_k.erase(it);
    }

    for (int i = 1; i <= n; ++i) if (a[i] == -1) a[i] = k + 1;

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}


// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
