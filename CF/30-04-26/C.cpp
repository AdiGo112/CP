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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi six, two, three, other;
    for (int i = 0; i < n; i++) {
        if (a[i] % 6 == 0)
            six.push_back(a[i]);
        else if (a[i] % 3 == 0)
            three.push_back(a[i]);
        else if (a[i] % 2 == 0)
            two.push_back(a[i]);
        else
            other.push_back(a[i]);
    }
    vi ans;
    for (int a : six) ans.push_back(a);
    for (int a : three) ans.push_back(a);
    for (int a : other) ans.push_back(a);
    for (int a : two) ans.push_back(a);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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