#include <bits/stdc++.h>
using namespace std;

const int n = 100;
vector<int> a(n), b(n);


//-------------Sort by keeping track of original indices-------------//
void ordered_indices_sort_example() {
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) -> bool{
        return b[x] < b[y];
    });
}

//----------------- MAIN -----------------//
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
    }

    return 0;
}