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

void solve2() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n <= 3){
        cout << 0 << "\n";
        return;
    }

    
}
ll stepCount(vector<int>& a, int num) {
    vi pos;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == num) {
            pos.pb(i);
        }
    }

    int m = pos.size();
    if (m <= 1) {
        return 0;
    }

    // Adjust positions
    vi adj(m);
    for (int i = 0; i < m; i++) {
        adj[i] = pos[i] - i;
    }

    // Median
    ll median = adj[m / 2];

    ll steps = 0;
    for (int i = 0; i < m; i++) {
        steps += llabs(adj[i] - median);
    }
    return steps;
}
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'a') a[i] = 0;
        else a[i] = 1;
    }
    ll steps = min(stepCount(a, 0), stepCount(a, 1));

    

    cout << steps << "\n";
}



//==================== MAIN ======================//
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}