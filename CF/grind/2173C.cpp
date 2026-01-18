#include <bits/stdc++.h>
using namespace std;

//==================== TYPEDEFS ====================//
using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vpi = vector<pii>;

//==================== MACROS =====================//
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(x) ((int)(x.size()))

//================== FAST I/O ===================//
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

//================== DEBUGGING ==================//
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << "\n"
#else
#define debug(x)
#endif

//=============== COMMON FUNCTIONS ==============//
const ll INF = 1e18;
const int MOD = 1e9 + 7;

//================ SOLVE FUNCTION =================//

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    unordered_map<ll, int> freq;
    for (ll x : a) freq[x] = 1;

    set<ll> s(all(a));
    vi ans;

    while (!s.empty()) {
        ll t = *s.begin();
        ans.pb(t);
        s.erase(s.begin());

        for (ll cur = t; cur <= k; cur += t) {
            if (!freq[cur]) {
                cout << -1 << "\n";
                return;
            }
            auto it = s.find(cur);
            if (it != s.end()) s.erase(it);
        }
    }

    cout << sz(ans) << "\n";
    for (ll x : ans) cout << x << " ";
    cout << "\n";
}


//==================== MAIN ======================//
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}