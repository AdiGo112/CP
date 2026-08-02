#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i<s.length(); i++){
        if(cnt0 == 0 && s[i] == '0') cnt0++;
        else if(cnt1 == 0 && s[i] == '1') cnt1++;
        else cout << s[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}