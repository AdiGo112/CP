#include <bits/stdc++.h>
using namespace std;

//==================== TYPEDEFS ====================//
using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using bigInt = __int128;

//==================== CONSTANTS ==================//
const ll INFLL = (ll)1e18;
const int INF  = (int)1e9;
const int MOD  = 1e9 + 7;

//==================== MACROS =====================//
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (int)((x).size())
#define PB      push_back
#define F first
#define S second
#define MP make_pair


//==================== FAST I/O ===================//
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

//==================== DEBUG ======================//
#ifdef LOCAL
    #define debug(x) cerr << "[DEBUG] " << #x << " = " << x << "\n"
    #define debugv(v) do { \
        cerr << "[DEBUG] " << #v << " = "; \
        for (auto &e : v) cerr << e << " "; \
        cerr << "\n"; \
    } while(0)
#else
    #define debug(x)
    #define debugv(v)
#endif

//==================== MATH UTILS =================//
ll mod_add(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a + b) % MOD;
}
ll mod_sub(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a - b + MOD) % MOD;
}
ll mod_mul(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a * b) % MOD;
}
ll mod_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        p >>= 1;
    }
    return res;
}

//==================== INPUT / OUTPUT =================//

// input for vector (size must already be set)
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto &x : v) in >> x;
    return in;
}

// output for vector
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) out << ' ';
        out << v[i];
    }
    return out;
}
// --------------- COMMON FUNCTIONS ---------------
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a,b) * b; }
string nthPermutation(string s,int k){
    vector<char> nums(s.begin(),s.end());
    int n = nums.size();
    vector<int> fact(n);
    fact[0] = 1;
    for(int i = 1; i < n; i++)fact[i] = fact[i-1] * i;
    k--; // zero-based
    string ans = "";
    for(int i = n; i >= 1; i--){
        int idx = k / fact[i-1];
        ans += nums[idx];
        nums.erase(nums.begin() + idx);
        k %= fact[i-1];}
    return ans;
}
//==================== SOLVE ======================//
//void solve() {
// int n;
// string X;
// cin >> n >> X;
// int lo = 1, hi = 1;
// for (int i = 0; i < n; i++) {
// int len = n - i;
// int new_lo = INT_MAX, new_hi = -1;
//     for (int L : {lo, hi}) {
//         if (L < lo || L > hi) continue;
//         int R = L + len - 1;
//         if (L > R) continue;
//         char leftT  = (L % 2 ? 'a' : 'b');
//         char rightT = (R % 2 ? 'a' : 'b');
//         char c = X[i];
//         if (c == '?' || c == leftT) {
//             new_lo = min(new_lo, L + 1);
//             new_hi = max(new_hi, L + 1);
//         }
//         if (c == '?' || c == rightT) {
//             new_lo = min(new_lo, L);
//             new_hi = max(new_hi, L);
//         }
//     }
//     if (new_lo > new_hi) {
//         cout << "NO";
//         return;
//     }
//     lo = new_lo;
//     hi = new_hi;
// }
// cout << "YES";
//}
void solve() {
    int n;
    string X;
    cin >> n >> X;
    int lo[2] = {INT_MAX, 1};
    int hi[2] = {-1, 1};
    for (int i = 0; i < n; i++) {
        int nlo[2] = {INT_MAX, INT_MAX};
        int nhi[2] = {-1, -1};
        int len = n - i;
        for (int p = 0; p < 2; p++) {
            if (lo[p] > hi[p]) continue;
            for (int L : {lo[p], hi[p]}) {
                if (L < lo[p] || L > hi[p]) continue;
                int R = L + len - 1;
                if (L > R) continue;
                char leftT  = (L % 2 ? 'a' : 'b');
                char rightT = (R % 2 ? 'a' : 'b');
                char c = X[i];
                if (c == '?' || c == leftT) {
                    int nl = L + 1;
                    int np = nl % 2;
                    nlo[np] = min(nlo[np], nl);
                    nhi[np] = max(nhi[np], nl);
                }
                if (c == '?' || c == rightT) {
                    int nl = L;
                    int np = nl % 2;
                    nlo[np] = min(nlo[np], nl);
                    nhi[np] = max(nhi[np], nl);
                }
            }
        }
        lo[0] = nlo[0]; hi[0] = nhi[0];
        lo[1] = nlo[1]; hi[1] = nhi[1];
        if (lo[0] > hi[0] && lo[1] > hi[1]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}
//==================== MAIN =======================//
int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
