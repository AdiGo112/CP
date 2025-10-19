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

bool isNonDecreasing(const string &p) {
    for (int i = 1; i < p.size(); i++)
        if (p[i] < p[i-1]) return false;
    return true;
}

bool isPalindrome(const string &x) {
    int l = 0, r = x.size() - 1;
    while (l < r) {
        if (x[l] != x[r]) return false;
        l++; r--;
    }
    return true;
}

void solve() {
    long long a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> ops;
    long long curr = a;

    // Repeat until curr becomes b
    while (curr != b) {
        long long diff = curr ^ b;

        // Pick the highest set bit in diff that is also set in curr
        long long x = 1LL << 31;
        while (x > 0 && ((diff & x) == 0 || (curr & x) == 0)) {
            x >>= 1;
        }

        // Safety: if no valid x found, break (should not happen)
        if (x == 0) break;

        ops.push_back(x);
        curr ^= x;
    }

    if (curr != b) {
        cout << -1 << "\n"; // transformation impossible
    } else {
        cout << ops.size() << "\n";
        for (long long x : ops) cout << x << " ";
        cout << "\n";
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
