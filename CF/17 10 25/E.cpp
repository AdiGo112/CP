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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> res;
    vector<char> present(n+1, 0), used_res(n+1, 0);
    for (int v : a) if (1 <= v && v <= n) present[v] = 1;

    // collect missing values in [1..n]
    for (int v = 1; v <= n && (int)res.size() < k; v++) {
        if (!present[v]) {
            res.push_back(v);
            used_res[v] = 1;
            a.push_back(v);
        }
    }

    // if still need, pick other unused values (ensure res values are distinct)
    while ((int)res.size() < k) {
        int last = a.back();
        int choose = -1;
        // prefer a value != last
        for (int v = 1; v <= n; v++) {
            if (!used_res[v] && v != last) { choose = v; break; }
        }
        // if none found (rare when only one value left and equals last), pick any unused
        if (choose == -1) {
            for (int v = 1; v <= n; v++) {
                if (!used_res[v]) { choose = v; break; }
            }
        }
        // Safety: since k <= n, choose must be found
        res.push_back(choose);
        used_res[choose] = 1;
        a.push_back(choose);
    }

    for (int i = 0; i < (int)res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
