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
//==================== PERMUTATION FUNCTION ====================//
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
    int n, m, k;
    cin >> n >> m >> k;

    vll robot(n), spike(m);
    cin >> robot >> spike;

    sort(all(robot));
    sort(all(spike));

    string s;
    cin >> s;

    vi left(k), right(k);

    int l = 0, r = 0, curr = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == 'L') curr++;
        else curr--;

        l = max(l, curr);
        r = max(r, -curr);

        left[i] = l;
        right[i] = r;
    }

    vi prefL(n, -1), prefR(n, -1);

    // LEFT
    for(int i = 0; i < n; i++){
        int idx = lower_bound(spike.begin(), spike.end(), robot[i]) - spike.begin();
        if(idx > 0)
            prefL[i] = abs(spike[idx-1] - robot[i]);
    }

    // RIGHT
    int j = m-1;
    for(int i = n-1; i >= 0; i--){
        while(j >= 0 && spike[j] > robot[i])
            j--;

        if(j < m-1)
            prefR[i] = spike[j+1] - robot[i];
    }

    /* -------- find death time -------- */

    vi death(k+1, 0);

    for(int i = 0; i < n; i++){
        int t = k+1;

        if(prefL[i] != -1){
            int pos = lower_bound(all(left), prefL[i]) - left.begin();
            if(pos < k) t = min(t, pos+1);
        }

        if(prefR[i] != -1){
            int pos = lower_bound(all(right), prefR[i]) - right.begin();
            if(pos < k) t = min(t, pos+1);
        }

        if(t <= k) death[t]++;
    }

    /* -------- print alive -------- */

    int alive = n;
    for(int i = 1; i <= k; i++){
        alive -= death[i];
        cout << alive << " ";
    }
    cout << "\n";
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
