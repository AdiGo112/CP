#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; 
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    if (n == 2) {
        cout << -1 << "\n";
        return;
    }
    cout << 1 << " " << 2;

    long long current = 3;
    for (int i = 3; i <= n; i++) {
        cout << " " << current;
        current *= 2;
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}