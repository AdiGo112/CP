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

    auto query = [&](int type, int l, int r) {
        ll x;
        cout << type << " " << l << " " << r << endl;
        cout.flush();
        cin >> x;
        return x;
    };

    // total increment = r - l + 1
    ll total_inc = query(2, 1, n) - (1LL * n * (n + 1) / 2);

    // find l using prefix binary search
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        ll p_sum = query(1, 1, mid);
        ll a_sum = query(2, 1, mid);

        if (a_sum > p_sum)
            hi = mid;
        else
            lo = mid + 1;
    }

    int L = lo;
    int R = L + total_inc - 1;

    cout << "! " << L << " " << R << endl;
    cout.flush();
}

//==================== MAIN ======================//
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}