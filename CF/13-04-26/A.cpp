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
    vector<bool> a(101, false);
    bool flag = false;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(a[x]){
            flag = true;
        }
        a[x] = true;
    }
    if(flag){
        cout << "-1\n";
        return;
    }
    for(int i=100; i> 0; i--){
        if(a[i]) cout << i << " ";
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
