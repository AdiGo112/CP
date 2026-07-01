#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool bob = true;
    int zero = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            zero++;
        } else {
            if (zero % 2 != 0) {
                bob = false;
            }
        }
    }
    int one = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one++;
        } else {
            if (one % 2 != 0) {
                bob = false;
            }
        }
    }
    cout << (bob ? "Bob" : "Alice") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}