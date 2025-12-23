#include <bits/stdc++.h>
using namespace std;

// ----------------- MACROS -----------------
#define all(v) v.begin(), v.end()
#define pb push_back
#define pf push_front
#define sz(x) ((int)(x.size()))
#define int long long
#define str string
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pii>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<str>
#define um unordered_map<int,int>
#define umci unordered_map<char,int>
#define forn(i,n) for(int i=0;i<(n);i++)
#define form(a, n) for(int i=a; i<n; i++)
#define vin(v, n) vi v(n); forn(i,n) cin>>v[i];

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

// ---------------- PRIME NUMBERS ------------------
vector<int> sieve_primes(int limit) {
    vector<char> is(limit+1, true);
    vector<int> primes;
    is[0]=is[1]=false;
    for (int i=2;i<=limit;i++){
        if(is[i]){
            primes.push_back(i);
            if (i*i <= limit)
                for (int j=i*i;j<=limit;j+=i) is[j]=false;
        }
    }
    return primes;
}

// ----------------- SOLVE FUNCTION -----------------

void solve(){

}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;
    //int primeLimit = 31623; //comment out this when prime numbers are needed
    //auto primes = sieve_primes(primeLimit);
    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
