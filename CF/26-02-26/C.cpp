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
// void solve(){
//     int n; cin >> n;
//     vector<vi> a(n);
//     for(int i=0; i<n; i++){
//         int m; cin >> m;
//         a[i].resize(m);
//         cin >> a[i];
//         reverse(all(a[i]));
//     }
//     sort(all(a));
//     unordered_set<int> seen;
//     vi ans;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<(int)a[i].size(); j++){
//             if (seen.find(a[i][j]) == seen.end()){
//                 seen.insert(a[i][j]);
//                 ans.PB(a[i][j]);
//             }
//         }
//     }
//     cout << ans;
// }
bool seen_a[1000005];
bool seen[1000005];

void solve() {
    int n;
    cin >> n;
    vector<vi> b(n);
    vi added_a;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vi a(l);
        cin >> a;

        vi temp;
        for (int j = l - 1; j >= 0; --j) {
            if (!seen_a[a[j]]) {
                temp.PB(a[j]);
                seen_a[a[j]] = true;
                added_a.PB(a[j]);
            }
        }
        b[i] = temp;
        for (int x : added_a) seen_a[x] = false;
        added_a.clear();
    }

    vi Q;
    vector<bool> used(n, false);
    
    while (true) {
        int best_i = -1;
        vi best_b_prime;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            vi b_prime;
            for (int x : b[i]) {
                if (!seen[x]) {
                    b_prime.PB(x);
                }
            }
            if (b_prime.empty()) {
                used[i] = true;
                continue;
            }
            if (best_i == -1 || b_prime < best_b_prime) {
                best_i = i;
                best_b_prime = b_prime;
            }
        }
        if (best_i == -1) break;
        used[best_i] = true;
        for (int x : best_b_prime) {
            Q.PB(x);
            seen[x] = true;
        }
    }
    cout << Q;

    for (int x : Q) {
        seen[x] = false;
    }
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
