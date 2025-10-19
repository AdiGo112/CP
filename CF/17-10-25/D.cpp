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

int query(int type, int l, int r) {
    cout << type << " " << l << " " << r << endl << endl;
    cout.flush();
    int response;
    cin >> response;
    return response;
}

void solve() {
    int n;
    cin >> n;
    
    // Query the entire range to get the total difference
    long long sum_p = query(1, 1, n);
    long long sum_a = query(2, 1, n);
    
    long long diff = sum_a - sum_p;
    
    // If diff == 0, no modification was made (l = r can be anything, let's say 1, 1)
    if (diff == 0) {
        cout << "! 1 1" << endl << endl;
        cout.flush();
        return;
    }
    
    // Binary search for l (leftmost modified position)
    int left = 1, right = n;
    int l_ans = 1;
    
    while (left < right) {
        int mid = (left + right) / 2;
        
        // Query range [1, mid] to see if there's any modification
        long long p_sum = query(1, 1, mid);
        long long a_sum = query(2, 1, mid);
        
        if (a_sum > p_sum) {
            // Modification starts at or before mid
            right = mid;
            l_ans = mid;
        } else {
            // Modification starts after mid
            left = mid + 1;
        }
    }
    l_ans = left;
    
    // Binary search for r (rightmost modified position)
    left = l_ans;
    right = n;
    int r_ans = n;
    
    while (left < right) {
        int mid = (left + right + 1) / 2;
        
        // Query range [mid, n] to see if there's any modification
        long long p_sum = query(1, mid, n);
        long long a_sum = query(2, mid, n);
        
        if (a_sum > p_sum) {
            // Modification extends to or beyond mid
            left = mid;
            r_ans = mid;
        } else {
            // Modification ends before mid
            right = mid - 1;
        }
    }
    r_ans = left;

    cout << "! " << l_ans << " " << r_ans << endl << endl;
    cout.flush();
}
// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
