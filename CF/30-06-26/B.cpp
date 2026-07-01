#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    string x;
    cin >> x;
    
    cout << "1";
    for(int i = 0; i < (int)x.length() - 1; i++) {
        cout << "0";
    }
    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}