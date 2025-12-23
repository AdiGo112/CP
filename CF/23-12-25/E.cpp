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
    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    vi p(n);
    int total = 0;
    forn(i, n) {
        cin >> p[i];
        total += p[i];
    }
    if(total > x + y){
        cout << "NO" << endl;
        return;
    }
    int curX = x;
    int curY = y;

    forn(i, n){
        if(s[i] == '0'){
            curX-= (p[i] / 2) + 1;
        }else{
            curY-= (p[i] / 2) + 1;
        }
        if(curX < 0 || curY < 0){
            cout << "NO"<< endl;
            return;
        }
    }
    bool diff = false;
    forn(i, n-1){
        if(s[i] != s[i+1]){
            diff = true;
            break;
        }
    }
    if(!diff){
        if(s[0] == '0'){
            if(x < y + n){
                cout << "NO" << endl;
                return;
            }
        }else{
            if(y < x + n){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}
// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
