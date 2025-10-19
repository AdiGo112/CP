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
    int n, k;
    cin >>n >> k;
    string s;
    cin>>s;
    int zero , one, two;
    zero = one = two = 0;
    for(char c : s) {
        if(c == '0') zero++;
        else if(c == '1') one++;
        else two++;
    }
    int rem = n - (zero + one);
    string ans(n, '+');
    for(int i=0; i<zero; i++) ans[i] = '-';
    for(int i = n-1; i>= n-one; i--) ans[i] = '-';

    for(int i = zero; i < zero + two; i++){
        if(ans[i]=='+') ans[i]='?';
    }
    for(int i = n-one-1; i>=n-one-two; i--){
        if(ans[i]=='+') ans[i]='?';
    }
    if(rem == two){
        for(int i = zero; i< zero + rem; i++) ans[i] = '-';
    }
    cout<<ans<<endl;
}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
