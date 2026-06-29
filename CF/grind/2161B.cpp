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
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> blackCell;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                blackCell.push_back({i, j});
            }
        }
    }
    if (blackCell.size() <= 1) {
        cout << "YES\n";
        return;
    }
    int minSum = 1e9, maxSum = -1e9;
    int minDiff = 1e9, maxDiff = -1e9;
    int minX = 1e9, maxX = -1e9;
    int minY = 1e9, maxY = -1e9;

    for (auto [x, y] : blackCell) {
        minSum = min(minSum, x + y);
        maxSum = max(maxSum, x + y);

        minDiff = min(minDiff, x - y);
        maxDiff = max(maxDiff, x - y);

        minX = min(minX, x);
        maxX = max(maxX, x);

        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    // Zigzag condition 1
    if (maxSum - minSum <= 1) {
        cout << "YES\n";
        return;
    }

    // Zigzag condition 2
    if (maxDiff - minDiff <= 1) {
        cout << "YES\n";
        return;
    }

    // 2x2 square condition
    if (maxX - minX <= 1 && maxY - minY <= 1) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}