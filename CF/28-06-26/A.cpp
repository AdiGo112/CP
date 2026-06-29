#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end();

void solve() {
    int n, c;
    cin >> n >> c;
    vi a(n);
    vi b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    int ok = true;
    long long ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] < b[i]){
            ok = false;
        }
        if(ok){
            ans += a[i] - b[i];
        }
    }
    if(ok){
        cout << ans << '\n';
        return;
    }
    ans = c;
    ok = true;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<n; i++){
        if(a[i] < b[i]){
            ok = false;
        }
        if(ok){
            ans += a[i] - b[i];
        }
    }
    if(ok){
        cout << ans << '\n';
        return;
    }else{
        cout << -1 <<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}