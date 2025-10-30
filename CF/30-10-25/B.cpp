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


void solve(){
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        // Check if the initial grid already has 3 consecutive black cells
        bool initial_invalid = false;
        
        // Check horizontally
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (grid[i][j] == '#' && grid[i][j+1] == '#' && grid[i][j+2] == '#') {
                    initial_invalid = true;
                    break;
                }
            }
            if (initial_invalid) break;
        }

        // Check vertically
        if (!initial_invalid) {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n - 2; i++) {
                    if (grid[i][j] == '#' && grid[i+1][j] == '#' && grid[i+2][j] == '#') {
                        initial_invalid = true;
                        break;
                    }
                }
                if (initial_invalid) break;
            }
        }

        if (initial_invalid) {
            cout << "NO\n";
            return;
        }


        vector<pair<int,int>> blacks;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#')
                    blacks.push_back({i, j});
            }
        }

        // If no black cells, condition can always be satisfied by painting one cell
        if (blacks.empty()) {
            cout << "YES\n";
            return;
        }

        bool ok = true;

        // For every pair of black cells, check the condition
        for (int i = 0; i < (int)blacks.size() && ok; i++) {
            for (int j = i + 1; j < (int)blacks.size(); j++) {
                auto [x1, y1] = blacks[i];
                auto [x2, y2] = blacks[j];
                int dx = abs(x1 - x2);
                int dy = abs(y1 - y2);

                // valid if: on same diagonal (↘↙↗↖) or just neighbouring diagonal
                if (!(dx == dy || abs(dx - dy) == 1)) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
}
// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}