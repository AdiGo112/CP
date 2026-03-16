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
void solve(){
    ll a,b,c,m;
    cin >> a >> b >> c >> m;

    ll A = m / a;
    ll B = m / b;
    ll C = m / c;

    ll ab = lcm(a,b);
    ll ac = lcm(a,c);
    ll bc = lcm(b,c);
    ll abc = lcm(ab,c);

    ll AB = m / ab;
    ll AC = m / ac;
    ll BC = m / bc;
    ll ABC = m / abc;

    ll A_only = A - AB - AC + ABC;
    ll B_only = B - AB - BC + ABC;
    ll C_only = C - AC - BC + ABC;

    ll AB_only = AB - ABC;
    ll AC_only = AC - ABC;
    ll BC_only = BC - ABC;

    ll alice = 6*A_only + 3*(AB_only + AC_only) + 2*ABC;

    ll bob = 6*B_only + 3*(AB_only + BC_only) + 2*ABC;

    ll carol = 6*C_only + 3*(AC_only + BC_only) + 2*ABC;

    cout << alice << " " << bob << " " << carol;
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
