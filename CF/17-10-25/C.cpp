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
    long long a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    // If b has a higher most-significant bit than a, impossible
    int kb = 63 - __builtin_clzll(b);
    int ka = 63 - __builtin_clzll(a);
    if (kb > ka) {
        cout << -1 << "\n";
        return;
    }

    long long x = a ^ b;
    if (x <= a) {
        cout << 1 << "\n" << x << "\n";
        return;
    }

    // Two-step construction: make a all-ones up to msb(a), then to b
    long long allones = ((1LL << (ka + 1)) - 1);
    long long x1 = a ^ allones;       // x1 <= a
    long long x2 = allones ^ b;       // x2 <= allones (which becomes new a)
    cout << 2 << "\n" << x1 << " " << x2 << "\n";
}
// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
