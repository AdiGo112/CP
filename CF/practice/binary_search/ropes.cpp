#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int,int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()


//==================== SOLVE ======================//
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto &x : a) cin >> x;

    double l = 0, r = 1e7, ans = 0;
    for(int i=0; i<200; i++){
        double mid = l + (r - l) / 2;
        int count = 0;
        for(int &x : a) count += (int) (x / mid);
        if(count >= k) ans = mid, l = mid;
        else r = mid;
    }
    cout << setprecision(10) << ans << "\n";
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) solve();
}