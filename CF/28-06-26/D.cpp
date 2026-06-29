#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    
    ll c1 = 0;
    ll c2 = 0;
    
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            c1++;
            while (n % i == 0) {
                c2++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        c1++;
        c2++;
    }
    cout << c1 + c2 - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}