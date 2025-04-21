#include <bits/stdc++.h>
#include <vector>
#include <set>
#define endl '\n'

using namespace std;

const long long DIM = 1007;
const long long INF = 1e12;
const long long MAX = 100003;

vector <long long>v[DIM];
long long Ans, A, B, all, R, C, n, m, k, p, mm, vis[DIM], x[DIM], y[DIM];
char c;
set <long long> ans;

void dfs(int x) {
    vis[x] = 1;
    for (auto to : v[x]) {
        if (vis[to] == 0) {
            dfs(to);

        }

    }

    return;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (abs(x[i] - x[j]) <= 1 && abs(y[i] - y[j]) <= 1) {
                v[i].push_back(j);
                v[j].push_back(i);
            }


    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            all++;
            dfs(i);
        }
    }
    cout << all;

    return 0;
}