#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
bool canReach(int x, int y) {
    if ((x + y) % 3 != 0) return false;
    if (y > x / 2) return false;
    if (y < -x / 4) return false;
    return true;
}
void solve() {
    int x, y;
    cin >> x >> y;
    cout << (canReach(x, y) ? "YES\n" : "NO\n");
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}