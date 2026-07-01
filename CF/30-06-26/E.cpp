#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vi> adj(n + 1);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi par(n + 1), ord, sz(n + 1, 1);
    vector<char> vis(n + 1);
    ord.reserve(n);
    
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ord.push_back(u);
        for (int v : adj[u])
            if (!vis[v]) vis[v] = 1, par[v] = u, q.push(v);
    }
    
    for (int i = n - 1; i >= 0; i--)
        if (par[ord[i]]) sz[par[ord[i]]] += sz[ord[i]];

    ll ans = 0, P = n - 1;
    for (int m = 1; m <= n; m++) {
        ll r = sqrtl(a[m]);
        while (r * r > a[m]) r--;
        while ((r + 1) * (r + 1) <= a[m]) r++;
        if (r * r != a[m]) continue;

        ll p2 = 0, p3 = 0;
        for (int v : adj[m]) {
            ll c = (v == par[m]) ? P - sz[m] + 1 : sz[v];
            p2 += c * c;
            p3 += c * c * c;
        }
        ll e2 = (P * P - p2) / 2;
        ll e3 = (e2 * P - P * p2 + p3) / 3;
        ans += e2 + e3;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}