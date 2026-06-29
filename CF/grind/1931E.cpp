#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        reverse(all(a[i]));
        if(a[i][0] == '0') b.push_back(a[i]);
        else cnt += a[i].length();
    }
    sort(all(b));
    for(int i = 0; i < (int) b.size(); i+=2){
        while (b[i][0] == '0') b[i].erase(0, 1);
    }
    
    for(int i=0; i< (int) b.size(); i++){
        cnt += b[i].length();
    }
    if(cnt > m) cout << "Sasha\n";
    else cout << "Anna\n";
}        
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
