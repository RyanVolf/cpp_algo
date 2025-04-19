#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const long long DIM = 50007;
const long long INF = 1000000000000000007LL;

long long n, m, v1, v2, par[DIM], c;





long long boss(int v) {
    if (par[v] == v) return v;
    else return par[v] = boss(par[v]);

}

bool uni(int p1, int p2) {
    int b1 = boss(p1);
    int b2 = boss(p2);

    if (b1 == b2) {
        return true;
    }

    if (rand() % 2 == 0)
        par[b1] = b2;
    else
        par[b2] = b1;
    return false;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;

    }

    for (int i = 1; i <= m; i++) {
        cin >> v1 >> v2;
        if (uni(v1, v2) == false)
            c++;

        if (c == n - 1) {
            cout << i;
            return 0;
        }
    }

    return 0;
}