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

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> nxt(n), prv(n);
    for (int i = 0; i < n; i++) {
        nxt[i] = i+1;
        prv[i] = i-1;
    }

    auto erasePos = [&](int x) {
        if (prv[x] >= 0) nxt[prv[x]] = nxt[x];
        if (nxt[x] < n) prv[nxt[x]] = prv[x];
    };

    int start = -1;
    for (int i = 0; i < n; i++) if (p[i] == 1) start = i;

    deque<int> q;
    q.push_back(start);
    erasePos(start);

    int visited = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop_front();

        // move right
        int r = nxt[cur];
        while (r < n) {
            if (p[r] > p[cur]) {
                q.push_back(r);
                erasePos(r);
                visited++;
                r = nxt[cur];
            } else {
                r = nxt[r];
            }
        }

        // move left
        int l = prv[cur];
        while (l >= 0) {
            if (p[l] < p[cur]) {
                q.push_back(l);
                erasePos(l);
                visited++;
                l = prv[cur];
            } else {
                l = prv[l];
            }
        }
    }

    cout << (visited == n ? "Yes\n" : "No\n");
}



// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
