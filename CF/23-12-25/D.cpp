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

    int N = 1 << n;
    int cur = N - 1;

    vector<char> used(N, 0);

    priority_queue<pii> pq;

    forn(x, N) {
        int score = __builtin_popcount(cur & x);
        pq.push({score, -x});
    }

    forn(step, N) {
        while (true) {
            auto [score, negx] = pq.top();
            pq.pop();

            int x = -negx;
            if (used[x]) continue;

            int realScore = __builtin_popcount(cur & x);

            // outdated entry → reinsert
            if (realScore != score) {
                pq.push({realScore, -x});
                continue;
            }

            // valid best choice
            used[x] = 1;
            cout << x << (step + 1 < N ? ' ' : '\n');
            cur &= x;
            break;
        }
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
