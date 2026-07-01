#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

// Overload the << operator to easily print __int128 with std::cout
std::ostream& operator<<(std::ostream& os, __int128 n) {
    if (n == 0) return os << 0;
    std::string s;
    bool neg = n < 0;
    if (neg) n = -n;
    while (n > 0) {
        s += '0' + (n % 10);
        n /= 10;
    }
    if (neg) s += '-';
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto& z : a) cin >> z;

    __int128 ans = 0;
    stack<ll> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[i] % a[s.top()] > 0) {
            // Cast to __int128 before multiplication to avoid 64-bit overflow
            ans += (__int128)(n - i) * min(a[i] % a[s.top()], a[s.top()] - a[i] % a[s.top()]);
            s.pop();
        }
        s.push(i);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}