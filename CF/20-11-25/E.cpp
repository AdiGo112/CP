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
    int n; cin >> n;
        vector<int> ans;
        if(n <= 8){
            for(int i = 1; i <= n; ++i) ans.push_back(i);
        } else {
            ans = {4,1,6,3,5,2};
            for(int x = 7; x <= n; x += 2){
                if(x + 1 <= n){
                    ans.push_back(x+1);
                    ans.push_back(x);
                } else {
                    ans.push_back(x);
                }
            }
        }
        // print
        for(int i = 0; i < n; ++i){
            if(i) cout << ' ';
            cout << ans[i];
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
