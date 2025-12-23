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

    vi mx(n+1, 0);
    vi mn(n+1, 0);
    while(q--) {
        int c, l, r;
        cin >> c >> l >> r;
        for(int i = l; i <= r; i++) {
            if(c == 2) {
                mx[i] = 1;
            } else {
                mn[i] = 1;
            }
        }
    }
    vi result(n+1, 0);
    for(int i = 1; i <= n; i++) {
        if(mx[i] == 1 && mn[i] == 1) {
            result[i] = k + 1;
        } else if(mn[i] == 1) {
            result[i] = k;
        } else {
            result[i] = i % k;
        }
    }
    for (int i= 1; i<=n; i++) {
        cout << result[i] << " ";
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
