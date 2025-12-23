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
    vi odds, evens;
    forn(i, n) {
        int x; cin >> x;
        if (x % 2) odds.pb(x);
        else evens.pb(x);
    }

    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    int O = odds.size();
    int E = evens.size();

    vi preE(E + 1, 0);
    forn(i, E) preE[i + 1] = preE[i] + evens[i];

    if (O == 0) {
        forn(k, n) cout << 0 << (k == n - 1 ? '\n' : ' ');
        return;
    }

    int largest_odd = odds[0];
    for (int k = 1; k <= n; k++) {
        int L = max((int)1, k - E);
        int R = min(k, O);
        int x0 = (L % 2 == 1) ? L : L + 1;
        if (x0 > R) {
            cout << 0 << (k == n ? '\n' : ' ');
            continue;
        }
        int y = k - x0;
        int val = largest_odd + preE[y];
        cout << val << (k == n ? '\n' : ' ');
    }
}


// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
