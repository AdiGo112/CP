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

void solve(){
    int n;
    ll Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vll xs(n), ys(n);
    cin >> xs >> ys;

    vector<pll> pts(n);
    for (int i = 0; i < n; i++) {
        pts[i] = {xs[i], ys[i]};
    }
    sort(pts.begin(), pts.end());

    vector<pii> cols;
    for (int i = 0; i < n; ) {
        ll x = pts[i].first;
        ll mn = pts[i].second;
        ll mx = pts[i].second;
        int j = i + 1;
        while (j < n && pts[j].first == x) {
            mn = min(mn, pts[j].second);
            mx = max(mx, pts[j].second);
            j++;
        }
        cols.push_back({mn, mx});
        i = j;
    }

    ll dpLow = 0, dpHigh = 0;
    ll prevLow = 0, prevHigh = 0;
    ll prevX = Ax;
    bool first = true;

    for (int i = 0; i < (int)cols.size(); i++) {
        ll L = cols[i].first;
        ll H = cols[i].second;
        ll x = pts[i].first;

        ll dx = x - prevX;
        ll width = H - L;

        if (first) {
            dpLow  = dx + llabs(Ay - H) + width;
            dpHigh = dx + llabs(Ay - L) + width;
            first = false;
        } else {
            ll newLow = min(
                dpLow  + llabs(prevLow  - H),
                dpHigh + llabs(prevHigh - H)
            ) + width + dx;

            ll newHigh = min(
                dpLow  + llabs(prevLow  - L),
                dpHigh + llabs(prevHigh - L)
            ) + width + dx;
            dpLow = newLow;
            dpHigh = newHigh;
        }
        prevLow = L;
        prevHigh = H;
        prevX = x;
    }
    ll result = min(
        dpLow  + (Bx - prevX) + llabs(prevLow  - By),
        dpHigh + (Bx - prevX) + llabs(prevHigh - By)
    );
    cout << result << "\n";
}
//==================== MAIN =======================//
int main() {
    fastio;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
