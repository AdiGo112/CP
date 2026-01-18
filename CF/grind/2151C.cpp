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
    int n; cin>>n;
    vll a(2*n); cin>>a;
    sort(all(a));

    vll pair(n), ppre(n+1,0);
    for(int i=0;i<n;i++){
        pair[i]=a[2*n-1-i]-a[i];
        ppre[i+1]=ppre[i]+pair[i];
    }

    vll diff(2*n), even(2*n+1,0), odd(2*n+1,0);
    for(int i=0;i<2*n-1;i++)
        diff[i]=a[i+1]-a[i];

    for(int i=0;i<2*n;i++){
        even[i+1]=even[i];
        odd[i+1]=odd[i];
        if(i%2==0) even[i+1]+=diff[i];
        else odd[i+1]+=diff[i];
    }

    for(int i=0;i<n;i++){
        ll cur=0;
        cur+=ppre[i];
        
        int L=i;
        int R=2*n-i-1;

        if(L%2==0)
            cur+=even[R]-even[L];
        else
            cur+=odd[R]-odd[L];

        cout<<cur<<" ";
    }
    cout<<"\n";
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
