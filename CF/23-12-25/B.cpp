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
    cin >> n;
    vi a(n);
    forn (i,n) cin >> a[i];

    int S = 0;
    forn (i,n - 1) {
        S += abs(a[i] - a[i + 1]);
    }

    int best = 0;

    best = max(best, abs(a[0] - a[1]));

    best = max(best, abs(a[n - 2] - a[n - 1]));

    for (int k = 1; k + 1 < n; k++) {
        int gain = abs(a[k - 1] - a[k]) + abs(a[k] - a[k + 1]) - abs(a[k - 1] - a[k + 1]);
        best = max(best, gain);
    }

    cout << S - best << "\n";
}


// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
