#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

bool check(string s, char c){
    int first = -1;
    int last = -1;
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == c){
            if(first == -1) first = i;
            last = i;
        }
    }
    for(int i = first; i <= last; i++){
        if(s[i] != c) return true;
    }
    return false;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = count(all(s), '0');
    int cnt1 = count(all(s), '1');

    if(!cnt0 || !cnt1){
        cout << 1 << "\n";
        return;
    }
    if(check(s, '0') || check(s, '1')){
        cout << 1 << "\n";
        return;
    }
    cout << 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}