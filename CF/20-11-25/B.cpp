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
    forn(i, n) cin >> a[i];
    if(a[0] == -1 || a[n-1] == -1) {
        if(a[n-1] != -1){
            a[0] = a[n-1];
        }
        else if(a[0] != -1){
            a[n-1] = a[0];
        }
        else{
            a[0] = 0;
            a[n-1] = 0;
        }
    }
    forn(i, n) {
        if(a[i] == -1) {
            a[i] = 0;
        }
    }
    cout<< abs(a[n-1] - a[0]) << '\n';
    forn(i, n) {
        cout << a[i] << ' ';
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
