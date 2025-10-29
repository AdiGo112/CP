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
struct Interval { int l, r; };

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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto &v : a) cin >> v;
    sort(all(a));

    if(k>1 && k == n){
        forn(i,n){
            cout<<a[i]<<" ";
        }
        return;
    }
    if(k==1){
        if(x-a[0] > a[0]){
            cout<<x <<endl;
            return;
        }else{
            cout<<0 <<endl;
            return;
        }
    }
    vector<int> teleports;
    auto possible = [&](int D) -> bool {
            if (D == 0) {
                // All integer positions 0..x are allowed
                return (x + 1) >= (int)k;
            }
            vector<Interval> ints;
            ints.reserve(n);
            int dshift = D - 1; // forbidden radius
            for (int val : a) {
                int L = max((int)0, val - dshift);
                int R = min(x, val + dshift);
                if (L <= R) ints.push_back({L, R});
            }
            if (ints.empty()) return (x + 1) >= (int)k;
            sort(ints.begin(), ints.end(), [](const Interval &A, const Interval &B){
                if (A.l != B.l) return A.l < B.l;
                return A.r < B.r;
            });
            // merge
            int covered = 0;
            int curL = ints[0].l, curR = ints[0].r;
            for (size_t i = 1; i < ints.size(); ++i) {
                if (ints[i].l <= curR + 1) {
                    curR = max(curR, ints[i].r);
                } else {
                    covered += (curR - curL + 1);
                    curL = ints[i].l;
                    curR = ints[i].r;
                }
            }
            covered += (curR - curL + 1);
            int allowed = (x + 1) - covered;
            return allowed >= (int)k;
        };

        // Binary search maximum D
        int lo = 0, hi = x + 1; // search in [0, x+1], hi is exclusive upper bound for binary-search style
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(mid)) {
                // mid is feasible, try larger
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int bestD = lo - 1; // lo is first infeasible, so best = lo-1

        // Reconstruct any k allowed integer positions for bestD
        vector<pair<int,int>> forb; // merged forbidden intervals
        if (bestD > 0) {
            int dshift = bestD - 1;
            for (int val : a) {
                int L = max((int)0, val - dshift);
                int R = min(x, val + dshift);
                if (L <= R) forb.push_back({L,R});
            }
            sort(forb.begin(), forb.end());
            vector<pair<int,int>> merged;
            for (auto &p : forb) {
                if (merged.empty() || p.first > merged.back().second + 1) {
                    merged.push_back(p);
                } else {
                    merged.back().second = max(merged.back().second, p.second);
                }
            }
            forb.swap(merged);
        } else {
            // no forbidden intervals when D == 0
            forb.clear();
        }

        vector<int> answer;
        answer.reserve(k);
        int pos = 0;
        size_t idx = 0;
        while ((int)answer.size() < k && pos <= x) {
            // if current pos is in forbidden interval, skip to end+1
            if (idx < forb.size() && pos >= forb[idx].first && pos <= forb[idx].second) {
                pos = forb[idx].second + 1;
                ++idx;
                continue;
            }
            if (idx < forb.size() && pos < forb[idx].first) {
                // gap before next forbidden interval: take as many as needed from pos..forb[idx].first-1
                int gapEnd = forb[idx].first - 1;
                while ((int)answer.size() < k && pos <= gapEnd) {
                    answer.push_back(pos);
                    ++pos;
                }
                // loop will handle skipping if needed
            } else if (idx >= forb.size()) {
                // no more forbidden intervals: take from pos..x
                while ((int)answer.size() < k && pos <= x) {
                    answer.push_back(pos);
                    ++pos;
                }
            } else {
                // pos > forb[idx].second (shouldn't happen due to the above skipping), just increment
                ++pos;
            }
        }

        // Fallback (should not be needed if binary search & reconstruction correct)
        if ((int)answer.size() < k) {
            // try filling arbitrarily (this shouldn't happen)
            for (int p = 0; p <= x && (int)answer.size() < k; ++p) {
                if (find(answer.begin(), answer.end(), p) == answer.end()) answer.push_back(p);
            }
        }

        // Output k integers (any order)
        for (int i = 0; i < k; ++i) {
            if (i) cout << ' ';
            cout << answer[i];
        }
        cout << '\n';


    
}

// ----------------- MAIN -----------------
int32_t main() {
    fastio;

    int t = 1;
    cin >> t;  // Comment this line if only one test case
    while(t--) solve();

    return 0;
}
