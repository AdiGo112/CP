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

// --------------- COMMON FUNCTIONS ---------------
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

// ----------------- SOLVE FUNCTION -----------------
void solve() {
    int n;
    cin >> n;
    vector<int> a(2*n);

    unordered_map<int,int> freq;
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    int odd = 0, even = 0;
    for (auto &p : freq) {
        if (p.second % 2 == 1) odd++;
        else even++;
    }
   
    if(odd>0){
        cout << odd + 2*even << "\n";
    }else{
        if(even%2==n%2){
           cout << odd + 2*even << "\n";
        }else{
           cout << odd + 2*even - 2 << "\n";
        }
    }

    
}



// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
