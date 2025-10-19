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

// --------------- COMMON FUNCTIONS -----------------
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

// new: global MAX and SPF + primes for linear sieve
const int MAXV = 200005;
static vector<int> spf;
static vector<int> primes;

void build_spf() {
    spf.assign(MAXV + 5, 0);
    primes.clear();
    for (int i = 2; i <= MAXV; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            long long v = 1LL * i * p;
            if (p > spf[i] || v > MAXV) break;
            spf[(int)v] = p;
        }
    }
}

// ----------------- SOLVE FUNCTION -----------------
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    vi b(n);
    forn(i, n) cin >> b[i];

    static vector<pair<int,int>> best1(MAXV+5, {INT_MAX, -1});
    static vector<pair<int,int>> best2(MAXV+5, {INT_MAX, -1});
    static vector<char> used(MAXV+5, 0);
    vector<int> touched;
    touched.reserve(128);

    auto add_candidate = [&](int p, int cost, int idx) {
        if (!used[p]) { used[p] = 1; touched.push_back(p); best1[p] = {INT_MAX, -1}; best2[p] = {INT_MAX, -1}; }
        if (cost < best1[p].first) {
            best2[p] = best1[p];
            best1[p] = {cost, idx};
        } else if (idx != best1[p].second && cost < best2[p].first) {
            best2[p] = {cost, idx};
        }
    };

    for (int i = 0; i < n; ++i) {
        int v = a[i];
        while (v > 1) {
            int p = spf[v];
            add_candidate(p, 0, i);
            while (v % p == 0) v /= p;
        }
        v = a[i] + 1;
        while (v > 1) {
            int p = spf[v];
            add_candidate(p, 1, i);
            while (v % p == 0) v /= p;
        }
    }

    long long ans = LLONG_MAX;
    for (int p : touched) {
        auto A = best1[p], B = best2[p];
        if (B.second == -1) continue;
        if (A.second != B.second) ans = min(ans, (long long)A.first + (long long)B.first);
        else {
        }
    }

    if (ans == LLONG_MAX) ans = 2;
    cout << ans << '\n';

    for (int p : touched) {
        used[p] = 0;
        best1[p] = {INT_MAX, -1};
        best2[p] = {INT_MAX, -1};
    }
}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    build_spf();

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}
