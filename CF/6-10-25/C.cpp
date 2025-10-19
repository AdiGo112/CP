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
    string s;
    cin >> n;
    cin >> s;

    int a = 0, b = 0;
    forn(i,n){
        if(s[i]=='a') a++;
        else b++;
    }

    if(a == b){
        cout << 0 << '\n';
        return;
    }

    int target = a - b;

    unordered_map<int,int> last;
    last.reserve(n*2 + 10);
    int pref = 0;
    last[0] = 0;
    int best = n + 1;

    for(int i = 1; i <= n; ++i){
        int val = (s[i-1]=='a') ? 1 : -1;
        pref += val;
        int need = pref - target;
        auto it = last.find(need);
        if(it != last.end()){
            int len = i - it->second;
            if(len < best) best = len;
        }
        last[pref] = i;
    }

    if(best == n+1) best = n;
    if(best == n) cout << -1 << '\n';
    else cout << best << '\n';
}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
