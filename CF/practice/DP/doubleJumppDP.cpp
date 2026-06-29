#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = unordered_map<int, int>;
using seti = unordered_set<int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    int N, K;
    cin >> N >> K;

    vi A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];

    // vector<int> minJump(n, INT_MAX);
    // minJump[0] = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j - i < i + k && j < n; j++) {
    //         int currScore = minJump[i];
    //         int currJump = a[i] * a[j];
    //         currScore += currJump;
    //         minJump[j] = min(minJump[j], currScore);
    //     }
    // }
    // cout << minJump[n - 1] << '\n';


     vector<int> dp(N, 1e5);
    dp[0] = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = max(0, i - K); j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + A[j] * A[i]);
        }
    }

   cout<< dp[N - 1]<<"\n";
}

//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
