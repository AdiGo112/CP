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
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

long long solve_one(int n, const vi &a, const vector<long long> &b) {
    const int TMAX = 30;
    const int MAXV = 200500; // >= max(ai)+TMAX
    static vector<int> spf;
    if (spf.empty()) {
        spf.assign(MAXV+1, 0);
        for (int i = 2; i <= MAXV; ++i) {
            if (spf[i] == 0) {
                for (int j = i; j <= MAXV; j += i) if (spf[j] == 0) spf[j] = i;
            }
        }
    }

    const long long INF = (long long)9e18;
    // store two smallest (cost, index) for each prime, with distinct indices
    static vector<pair<long long,int>> best1, best2;
    best1.assign(MAXV+1, {INF, -1});
    best2.assign(MAXV+1, {INF, -1});

    for (int i = 0; i < n; ++i) {
        int ai = (int)a[i];
        for (int t = 0; t <= TMAX; ++t) {
            int v = ai + t;
            if (v > MAXV) break;
            int temp = v;
            vector<int> primes;
            while (temp > 1) {
                int p = spf[temp];
                primes.push_back(p);
                while (temp % p == 0) temp /= p;
            }
            long long cost = (long long)t * b[i];
            for (int p : primes) {
                // add candidate (cost, i) ensuring best1 and best2 indices differ
                if (best1[p].second == -1) {
                    best1[p] = {cost, i};
                } else if (best1[p].second == i) {
                    // same index as best1: just tighten best1 if cost smaller
                    if (cost < best1[p].first) best1[p].first = cost;
                } else {
                    // different index
                    if (cost < best1[p].first) {
                        best2[p] = best1[p];
                        best1[p] = {cost, i};
                    } else if (best2[p].second == -1 || cost < best2[p].first) {
                        best2[p] = {cost, i};
                    }
                }
            }
        }
    }

    long long ans = INF;
    for (int p = 2; p <= MAXV; ++p) {
        if (best1[p].second != -1 && best2[p].second != -1) {
            // ensure indices distinct (construction guarantees it)
            if (best1[p].second != best2[p].second)
                ans = min(ans, best1[p].first + best2[p].first);
        }
    }
    if (ans == INF) ans = 0;
    return ans;
}

// ----------------- MAIN -----------------
// moved heavy parsing/flow into process_input(), keep main minimal
void process_input() {
    vector<long long> vals;
    long long x;
    while (cin >> x) vals.push_back(x);
    if (vals.empty()) return;

    auto try_parse_with_t = [&](vector<long long> &out_answers)->bool {
        size_t idx = 0;
        long long t = vals[idx++];
        for (long long tt = 0; tt < t; ++tt) {
            if (idx >= vals.size()) return false;
            long long n = vals[idx++]; if (n < 0) return false;
            if (idx + 2*n > vals.size()) return false;
            vi a((int)n);
            forn(i, n) a[i] = (int)vals[idx++];
            vector<long long> b((int)n);
            forn(i, n) b[i] = vals[idx++];
            out_answers.push_back(solve_one((int)n, a, b));
        }
        if (idx != vals.size()) return false;
        return true;
    };

    vector<long long> answers;
    if (try_parse_with_t(answers)) {
        for (auto ans : answers) cout << ans << '\n';
        return;
    }

    size_t idx = 0;
    long long n = vals[idx++];
    if (n < 0 || idx + 2*n > vals.size()) return;
    vi a((int)n);
    forn(i, n) a[i] = (int)vals[idx++];
    vector<long long> b((int)n);
    forn(i, n) b[i] = vals[idx++];
    cout << solve_one((int)n, a, b) << '\n';
}

int32_t main() {
    fastio;
    process_input();
    return 0;
}
