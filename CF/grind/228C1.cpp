#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
//==================== SOLVE ======================//
void solve() {
    using ll = long long;

    ll a;
    cin >> a;

    int n;
    cin >> n;

    vector<int> d(n);
    for (int &x : d) cin >> x;

    string s = to_string(a);

    auto buildGreater = [&]() {

        int m = s.size();
        string t = s;

        for (int i = 0; i < m; i++) {

            int cur = s[i] - '0';

            bool same = false;

            for (int x : d)
                if (x == cur)
                    same = true;

            if (same) continue;

            int bigger = -1;

            for (int x : d) {
                if (x > cur) {
                    bigger = x;
                    break;
                }
            }

            if (bigger != -1) {

                t[i] = char('0' + bigger);

                for (int j = i + 1; j < m; j++)
                    t[j] = char('0' + d[0]);

                return stoll(t);
            }

            int j = i - 1;

            while (j >= 0) {

                int here = t[j] - '0';

                int nxt = -1;

                for (int x : d) {
                    if (x > here) {
                        nxt = x;
                        break;
                    }
                }

                if (nxt != -1) {

                    t[j] = char('0' + nxt);

                    for (int k = j + 1; k < m; k++)
                        t[k] = char('0' + d[0]);

                    return stoll(t);
                }

                j--;
            }

            int first = -1;

            for (int x : d) {
                if (x != 0) {
                    first = x;
                    break;
                }
            }

            string res;
            res += char('0' + first);

            for (int j = 0; j < m; j++)
                res += char('0' + d[0]);

            return stoll(res);
        }

        return a;
    };

    auto buildSmaller = [&]() {

        int m = s.size();
        string t = s;

        for (int i = 0; i < m; i++) {

            int cur = s[i] - '0';

            bool same = false;

            for (int x : d)
                if (x == cur)
                    same = true;

            if (same) continue;

            int smaller = -1;

            for (int x : d)
                if (x < cur)
                    smaller = x;

            if (smaller != -1) {

                t[i] = char('0' + smaller);

                for (int j = i + 1; j < m; j++)
                    t[j] = char('0' + d.back());

                if (t[0] == '0')
                    return -1LL;

                return stoll(t);
            }

            int j = i - 1;

            while (j >= 0) {

                int here = t[j] - '0';

                int nxt = -1;

                for (int x : d)
                    if (x < here)
                        nxt = x;

                if (nxt != -1) {

                    t[j] = char('0' + nxt);

                    for (int k = j + 1; k < m; k++)
                        t[k] = char('0' + d.back());

                    if (t[0] == '0')
                        return -1LL;

                    return stoll(t);
                }

                j--;
            }

            if (m == 1)
                return -1LL;

            int first = -1;

            for (int x : d)
                if (x != 0)
                    first = x;

            if (first == -1)
                return -1LL;

            string res;
            res += char('0' + first);

            for (int j = 1; j < m - 1; j++)
                res += char('0' + d.back());

            return stoll(res);
        }

        return a;
    };

    ll bigger = buildGreater();
    ll smaller = buildSmaller();

    ll ans = abs(a - bigger);

    if (smaller != -1)
        ans = min(ans, abs(a - smaller));

    cout << ans << '\n';
}
//==================== MAIN =======================//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}