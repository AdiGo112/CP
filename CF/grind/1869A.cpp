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
    vi a (n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if(n & 1){
        cout << 5 << "\n";
        cout << 1 <<" " << n - 1 << "\n";
        cout << 1 << " " << n - 1 << "\n";
        cout << n - 1 << " " << n << "\n";
        cout << n - 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n"; 
    }else{
        cout << 2 << "\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n";
    }
}


//==================== MAIN ======================//
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}