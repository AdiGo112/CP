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
    vi a;
    cin >> n;
    a.resize(n);
    forn(i, n) cin >> a[i];

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int mx = *max_element(all(a));
    int pos = 0;
    forn(i, n) if (a[i] == mx) { pos = i; break; }
    vi b(n);
    for (int i = 0; i < n; ++i) b[i] = a[(pos + i) % n];

    int ans = 0;
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        int cur = b[i];
        while (!st.empty() && st.back() <= cur) {
            int mid = st.back(); st.pop_back();
            if (st.empty()) ans += cur;
            else ans += min(st.back(), cur);
        }
        st.push_back(cur);
    }
    while (st.size() > 1) {
        st.pop_back();
        ans += st.back();
    }
    cout << ans << '\n';
}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
