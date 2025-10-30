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
    long long X;
    cin >> n >> X;
    vector<long long> a(n);
    long long T = 0;
    for (int i = 0; i < n; ++i) { cin >> a[i]; T += a[i]; }

    long long K = T / X;
    if (K == 0) {
        // no triggers possible
        cout << 0 << "\n";
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << "\n";
        return;
    }

    // pick K largest as the triggering items
    sort(a.begin(), a.end(), greater<long long>());
    vector<long long> big(a.begin(), a.begin() + K);
    vector<long long> small(a.begin() + K, a.end());
    sort(small.begin(), small.end()); // use smallest fillers first

    long long bonus = 0;
    for (auto v : big) bonus += v;
    cout << bonus << "\n";

    // build an order that makes each big item trigger
    long long S = 0;
    vector<long long> res;
    size_t idx = 0; // index into small

    for (size_t i = 0; i < big.size(); ++i) {
        long long p = big[i];
        while (idx < small.size() && ((S % X) + p < X)) {
            res.push_back(small[idx]);
            S += small[idx];
            ++idx;
        }
        // append the big (triggering) item
        res.push_back(p);
        S += p;
    }

    // append remaining small items
    while (idx < small.size()) {
        res.push_back(small[idx]);
        ++idx;
    }

    // print the order
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << res[i];
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
