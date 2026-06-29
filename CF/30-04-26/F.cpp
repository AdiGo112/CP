#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
// Helper to print 128-bit integer
void print128(__int128 n) {
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Create the gravity-shifted (sorted) array
    vector<long long> b = a;
    sort(b.begin(), b.end());

    // Calculate Base Distance using 1-based indices and __int128_t for overflow protection
    __int128 base_dist = 0;
    for(int i = 0; i < n; i++) {
        base_dist += (__int128_t)(i + 1) * b[i];
        base_dist -= (__int128_t)(i + 1) * a[i];
    }

    long long max_extra = 0;
    for(int i = 0; i < n; i++) {
        // Find 1-based index (k) of the FIRST occurrence of a[i] in the sorted array
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        long long k = distance(b.begin(), it) + 1;
        
        // Calculate the extra momentum gained if we decreased a[i]
        long long extra = (i + 1) - k;
        if (extra > max_extra) {
            max_extra = extra;
        }
    }

    // Add the best operation (or 0 if doing nothing is better)
    __int128 max_total = base_dist + max_extra;
    print128(max_total);
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}