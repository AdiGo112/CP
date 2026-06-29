#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;
    int x = INT_MAX, y = INT_MAX;
    int ans = 0;
    for (int num : a) {
        // Maintain x <= y
        if (x > y)
            swap(x, y);
        if (num <= x) {
            // Case 1: num <= x
            x = num;
        }
        else if (num > y) {
            // Case 2: y < num
            ans++;
            x = num;
        }
        else {
            // Case 3: x < num <= y
            y = num;
        }
    }

    cout << ans << '\n';
}

//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}