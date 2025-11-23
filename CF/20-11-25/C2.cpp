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

    int n;
    if (!(cin >> n)) return;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int D = 0;
    for (int i = 0; i < n; ++i) D ^= (a[i] ^ b[i]);

    if (D == 0) {
        cout << "Tie\n";
        return;
    }

    int p = 31 - __builtin_clz(D);

    int last = -1;
    for (int i = 0; i < n; ++i) {
        if ( ((a[i] ^ b[i]) >> p) & 1 ) last = i + 1;
    }

    if (last == -1) {
        cout << "Tie\n";
        return;
    }

    if (last % 2 == 1) cout << "Ajisai\n";
    else cout << "Mai\n";
}




// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
