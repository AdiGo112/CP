#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
    ll n, k;
    cin >> n >> k;
    vi ans;
    int low = 1, high = n;
    while (low <= high) {
        ll rem = high - low;
        if (k >= rem) {
            ans.push_back(high);
            high--;
            k -= rem;
        } else {
            ans.push_back(low);
            low++;
        }
    }
    for (int x : ans)
        cout << x << ' ';

    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}