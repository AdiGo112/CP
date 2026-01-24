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
#define pb      push_back

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

string nthPermutation(string s, int k) {
    vector<char> nums(s.begin(), s.end());
    int n = nums.size();

    vector<int> fact(n);
    fact[0] = 1;
    for(int i = 1; i < n; i++)
        fact[i] = fact[i-1] * i;

    k--; // zero-based

    string ans = "";

    for(int i = n; i >= 1; i--) {
        int idx = k / fact[i-1];
        ans += nums[idx];
        nums.erase(nums.begin() + idx);
        k %= fact[i-1];
    }

    return ans;
}
//==================== SOLVE ======================//
int c_n_k[31][31];
void precompute(){
    for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
            if (i < j) c_n_k[i][j] = 0;
            else if (j == 0) c_n_k[i][j] = 1;
            else c_n_k[i][j] = c_n_k[i - 1][j] + c_n_k[i - 1][j - 1];
        }
    }
}
void solve(){   
    int n, k;
    cin >> n >> k;

    
    int d = 0;
    while (n % 2 == 0) {
        n /= 2;
        ++d;
    }

    int ans = 0;
    for (int max_bit = 0; max_bit < d; max_bit++) {
        for (int cnt_bit = 1; cnt_bit <= max_bit + 1; cnt_bit++) {
            if (max_bit + cnt_bit <= k) continue;
            ans += c_n_k[max_bit][cnt_bit - 1];
        }
    }

    if (d + 1 > k) ans++;
    cout << ans << "\n";
}
//==================== MAIN =======================//
int main() {
    fastio;
    precompute();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
