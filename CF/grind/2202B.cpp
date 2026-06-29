
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n;
    string X;
    cin >> n >> X;
    if (n % 2 == 1) {
        if (X[0] == 'b') {
            cout << "NO\n";
            return;
        }
    }
    if (n % 2 == 0) {
        for (int i = 0; i + 1 < n; i += 2) {
            if (X[i] != '?' && X[i + 1] != '?' && X[i] == X[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
    } else {
        for (int i = 1; i + 1 < n; i += 2) {
            if (X[i] != '?' && X[i + 1] != '?' && X[i] == X[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}