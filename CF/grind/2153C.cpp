#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll sum = 0;
    int cnt = 0;
    vector<ll> single;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        int count = j - i;
        ll num = a[i];

        if (count >= 2) {
            int pairs = count / 2;
            sum += (ll)pairs * num * 2;
            cnt += pairs * 2;
            count %= 2;
        }
        if (count == 1) {
            single.push_back(num);
        }
        i = j;
    }
    sort(single.rbegin(), single.rend());
    ll peri = 0;
    for (size_t i = 0; i + 1 < single.size(); i++) {
        if (single[i] < sum + single[i + 1]) {
            if (cnt + 2 >= 3) {
                peri = max(peri, sum + single[i] + single[i + 1]);
            }
        }
    }
    for (size_t i = 0; i < single.size(); i++) {
        if (single[i] < sum) {
            if (cnt + 1 >= 3) {
                peri = max(peri, sum + single[i]);
            }
            break;
        }
    }
    if (cnt >= 3) {
        peri = max(peri, sum);
    }
    cout << peri << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}