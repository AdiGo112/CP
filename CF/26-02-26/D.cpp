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
int cool(const vi& A) {
    int K = A.size();
    if (K == 0) return 0;
    vi depth_pge(K, 1);
    vi st;
    for (int i = 0; i < K; i++) {
        while (!st.empty() && A[st.back()] < A[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            depth_pge[i] = depth_pge[st.back()] + 1;
        } else {
            depth_pge[i] = 1;
        }
        st.PB(i);
    }
    vi depth_nge(K, 1);
    vi st2;
    for (int i = K - 1; i >= 0; i--) {
        while (!st2.empty() && A[st2.back()] < A[i]) {
            st2.pop_back();
        }
        if (!st2.empty()) {
            depth_nge[i] = depth_nge[st2.back()] + 1;
        } else {
            depth_nge[i] = 1;
        }
        st2.PB(i);
    }
    int max_len = 0;
    for (int i = 0; i < K; i++) {
        max_len = max(max_len, depth_pge[i] + depth_nge[i] - 1);
    }
    return max_len;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    int max_idx = 0;
    cin >> a;
    max_idx = find(all(a), n) - a.begin();
    vi right_part;
    for (int i = max_idx; i < n; i++) {
        right_part.PB(a[i]);
    }
    vi left_part;
    for (int i = max_idx; i >= 0; i--) {
        left_part.PB(a[i]);
    }
    int ans_right = cool(right_part);
    int ans_left = cool(left_part);
    int max_cool = max(ans_right, ans_left);
    cout << n - max_cool;
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
