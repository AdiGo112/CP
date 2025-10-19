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
    //solve function
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];

    vi pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++) pref[i] = max(pref[i-1], a[i]);

    int ans = 0;
    const int INF = (int)4e18;
    forn(i, n) {
        if(i % 2 == 0) {
            int left_max = (i > 0 ? pref[i-1] : INF);
            int right_max = (i + 1 < n ? pref[i+1] : INF);
            int neigh_min = min(left_max, right_max);

            int allowed = neigh_min - 1;
            if(allowed < 0) allowed = - (int)4e18;
            if(a[i] > allowed) ans += (a[i] - allowed);
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
