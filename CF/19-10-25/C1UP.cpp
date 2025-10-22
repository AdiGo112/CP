#include <bits/stdc++.h>
using namespace std;

// ----------------- MACROS -----------------
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(x) ((int)(x.size()))
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pii>
#define forn(i,n) for(int i=0;i<(n);i++)

// ---------------- FAST I/O ----------------
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

// --------------- DEBUGGING ---------------
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// --------------- COMMON FUNCTIONS -----------------
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a,b) * b; }
// ----------------- SOLVE FUNCTION -----------------
const int N = 2e5 + 10;
vector<vector<int>> pfac(N + 1);

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int ans = 2;
    map<int, int> cnt;
    for (int i = 0; i < n; i++){
        for (int x : pfac[a[i]]){
            if (cnt[x] > 0)
                ans = 0;
            cnt[x]++;
        }
    }

    for (int i = 0; i < n; i++){
        for (int x : pfac[a[i]])
            cnt[x]--;

        for (int x : pfac[a[i] + 1]){
            if (cnt[x] > 0)
                ans= min(ans, llabs(1));
        }

        for (int x : pfac[a[i]])
            cnt[x]++;
    }

    cout << ans << "\n";
}

// ----------------- MAIN -----------------
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i <= N; i++){
        if (!pfac[i].empty())
            continue;

        for (int j = i; j <= N; j += i)
            pfac[j].push_back(i);
    }
    
    int t;
    cin >> t;
    while (t--) solve();
}
