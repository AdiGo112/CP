#include <bits/stdc++.h>
using namespace std;

//==================== TYPEDEFS ====================//
using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vpi = vector<pii>;

//==================== MACROS =====================//
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(x) ((int)(x.size()))

//================== FAST I/O ===================//
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

//================== DEBUGGING ==================//
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << "\n"
#else
#define debug(x)
#endif

//=============== COMMON FUNCTIONS ==============//
const ll INF = 1e18;
const int MOD = 1e9 + 7;

//================ SOLVE FUNCTION =================//

void solve() {
    int n, k;
    cin >> n >> k;
    vi a (n);
    vi valid(n, 0);

    for(int i=0; i<n; i++){
        cin>>a[i];
        valid[a[i] - 1] = 1;
    }
    vi ans;
    if(n < 3){
        for(int i=0; i<k; i++){
            ans.pb(i%n + 1);
        }
    }else{
        vi three (3);
        for(int i=0; i<n; i++){
            if(valid[i] == 0){
                three[0] = i + 1;
                break;
            }
        }
        if(three[0] == 0){
            three[0] = a[0];
            three[1] = a[1];
            three[2] = a[2];
        }else{
            three[2] = a[n-1];
            for(int i=1; i<=n; i++){
                if(i != three[0] && i != three[2]){
                    three[1] = i;
                    break;
                }
            }
        }
        for(int i=0; i<k; i++){
            ans.pb(three[i%3]);
        }
    }
    for(int i=0; i<k; i++){
        cout<< ans[i]<<" ";
    }
    cout<<endl;
}


//==================== MAIN ======================//
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
