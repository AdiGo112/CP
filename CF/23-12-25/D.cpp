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
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n + 1), sgn(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int ballance = 0;
    for(int i = 1; i <= n; i++) {
        if (a[i] <= l) {
            sgn[i] = 1;
            ballance++;
        } else if (a[i] >= r) {
            sgn[i] = -1;
            ballance--;
        }
    }
    for(int i = 1, j = n; i <= n && j >= 1; i++, j--) {
        if (ballance > 0 && sgn[j] == 0) {
            sgn[j] = -1;
            ballance--;
        }
        if (ballance < 0 && sgn[i] == 0) {
            sgn[i] = 1;
            ballance++;
        }
    }
    int rem = 0;
    for(int i = 1; i <= n; i++) {
            rem+= (sgn[i] == 0);
    }
    for(int i = 1, j = 1; i <= n && j <= rem/2; i++) {
        if (sgn[i] == 0) {
            sgn[i] = 1;
            j++;
        }
    }
    for (int i = n, j = 1; i >= 1 && j <= rem / 2; i--) {
        if (sgn[i] == 0) sgn[i] = -1, j++;
    }
    int score_l = 0, score_r = 0;
    for (int i = 1; i <= n; i++) {
        if (sgn[i] == 1) score_l += l - a[i], score_r += r - a[i];
        else if (sgn[i] == -1) score_l += a[i] - l, score_r += a[i] - r;
    }
    int result = min(score_l, score_r);
    cout << result << "\n";
}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
