#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
const int MOD = 1e9 + 7;
const int MAXN = 40000;

vector<ll> dp(MAXN + 1);

bool isPal(int x) {
    int y = x;
    int rev = 0;
    while (y) {
        rev = rev * 10 + y % 10;
        y /= 10;
    }
    return rev == x;
}

void precompute() {
    vi pal;

    for (int i = 1; i <= MAXN; i++) {
        if (isPal(i)) pal.push_back(i);
    }

    dp[0] = 1;

    for (int p : pal) {
        for (int s = p; s <= MAXN; s++) {
            dp[s] = (dp[s] + dp[s - p]) % MOD;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t;
    while (t--) solve();
}