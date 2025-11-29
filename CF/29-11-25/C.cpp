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
struct Node {
    long long sum;
    long long pref;
    long long suff;
    long long best;
};

Node merge(const Node &L, const Node &R) {
    Node res;
    res.sum = L.sum + R.sum;
    res.pref = max(L.pref, L.sum + R.pref);
    res.suff = max(R.suff, R.sum + L.suff);
    res.best = max(max(L.best, R.best), L.suff + R.pref);
    return res;
}

struct SegTree {
    int n;
    vector<Node> st;

    SegTree(const vector<long long>& a) {
        n = a.size();
        st.resize(4*n);
        build(1, 0, n-1, a);
    }

    void build(int p, int l, int r, const vector<long long>& a) {
        if (l == r) {
            long long v = a[l];
            st[p] = {v, v, v, v};
            return;
        }
        int m = (l+r)/2;
        build(p*2, l, m, a);
        build(p*2+1, m+1, r, a);
        st[p] = merge(st[p*2], st[p*2+1]);
    }

    void update(int p, int l, int r, int idx, long long val) {
        if (l == r) {
            st[p] = {val, val, val, val};
            return;
        }
        int m = (l+r)/2;
        if (idx <= m) update(p*2, l, m, idx, val);
        else update(p*2+1, m+1, r, idx, val);
        st[p] = merge(st[p*2], st[p*2+1]);
    }

    void update(int idx, long long val) {
        update(1, 0, n-1, idx, val);
    }

    long long maxSubarraySum() {
        return st[1].best;
    }
};

long long maximizeOneAdd(const vector<long long>& a, const vector<long long>& b) {
    int n = a.size();
    SegTree seg(a);
    long long answer = seg.maxSubarraySum();

    for (int i = 0; i < n; i++) {
        seg.update(i, a[i] + b[i]);
        answer = max(answer, seg.maxSubarraySum());
        seg.update(i, a[i]); 
    }

    return answer;
}

int maxSubarraySum(const vector<int>& a) {
    // Kadane's algorithm
    int best = LLONG_MIN;
    int curr = 0;
    for (int x : a) {
        curr = max(x, curr + x);
        best = max(best, curr);
    }
    return best;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];



    if(k%2==0){
        //no change
        cout << maxSubarraySum(a) << "\n";
    }else{
        //alice plays last move
        cout << maximizeOneAdd(a, b) << "\n";
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
