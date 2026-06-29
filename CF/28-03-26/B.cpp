#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
const int MOD = 676767677;
int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}
void solve() {
    int x, y;
    cin >> x >> y;
    int S = x - y;
    if (S == 0) {
        cout << 1 << "\n";
        for (int i = 0; i < x; i++) cout << "1 ";
        for (int i = 0; i < y; i++) cout << "-1 ";
        cout << "\n";
        return;
    }
    int d = abs(S);
    cout << countDivisors(d) % MOD << "\n";
    if (x > y) {
        for (int i = 0; i < x; i++) cout << "1 ";
        for (int i = 0; i < y; i++) cout << "-1 ";
    } else {
        for (int i = 0; i < y; i++) cout << "-1 ";
        for (int i = 0; i < x; i++) cout << "1 ";
    }
    cout << "\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
