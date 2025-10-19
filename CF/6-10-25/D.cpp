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


inline long long C2(long long x){ return x*(x-1)/2; }

void solve(){
    int n, k;
    cin >> n >> k;

    long long total = C2(n);
    if(k < 0 || k > total){
        cout << 0 << '\n';
        return;
    }

    long long S = total - k;


    int maxS = (int) (C2(n));
    vector<vector<int>> prev(n+1, vector<int>(maxS+1, -1));
    prev[0][0] = 0;

    for(int pos = 0; pos <= n; ++pos){
        for(int ssum = 0; ssum <= maxS; ++ssum){
            if(prev[pos][ssum] == -1) continue;
            for(int len = 1; len <= n - pos; ++len){
                int ns = ssum + (int)C2(len);
                if(ns > maxS) break;
                if(prev[pos+len][ns] == -1){
                    prev[pos+len][ns] = len;
                }
            }
        }
    }

    if(S > maxS || prev[n][(int)S] == -1){
        cout << 0 << '\n';
        return;
    }
    vector<int> runs;
    int curPos = n;
    int curS = (int)S;
    while(curPos > 0){
        int len = prev[curPos][curS];
        runs.push_back(len);
        curS -= (int)C2(len);
        curPos -= len;
    }
    reverse(runs.begin(), runs.end());

    vector<int> ans;
    int cur = n;
    for(int r : runs){
        int start = cur - r + 1;
        for(int x = start; x <= cur; ++x) ans.push_back(x);
        cur -= r;
    }

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
