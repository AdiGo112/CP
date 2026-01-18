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
    cin >> n;
    vi p (n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vi pre (n + 1, n);
    for (int i = 1; i <= n; i++) {
        pre[i] = min(pre[i-1], p[i-1]);
    }
    
    vi suf (n + 2, 0);
    for(int i=n; i>=1; i--)
        suf[i] = max(suf[i+1], p[i-1]);
    for(int i = 0; i < n; i++) {
        if(pre[i] > suf[i+1]){
            cout<< "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";

}

//==================== MAIN ======================//
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}