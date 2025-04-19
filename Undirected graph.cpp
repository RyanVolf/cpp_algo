#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int DIM = 1000007;
const int INF = 1000000007;


long long  x, L, R, doublon[1007][1007], lich, mpl, mni1, mni2, mni3, mni4, mm, mni, mmi, rlon[DIM], rlon1[DIM], lon, lon1, maxi1, mini1, lon2, pl, lon3, lon4, lon5, lon6, lon7, lon8, mini, start, finish, maxi, dlon[DIM], have, need;
char ch, ch1, ch2, ch3, ch4, dch[DIM];
int in, in1, in2, in3;
set <char> sch;
set <long long> slon;
set <string> sstr;
map<string, long long> m;
long double lond, lond1, dlond[DIM], lond2, lond3, lond4;
int y;

long long v1, v2, w, c, N, M, res;

struct rec {
    int v1, v2, w;
};
rec G[1000007];

int findset(int x) {
    if (dlon[x] == x) return x;
    else return dlon[x] = findset(dlon[x]);
}

bool tof(int x, int y) {
    int xx = findset(x);
    int yy = findset(y);
    return xx == yy;
}

void unionset(int x, int y) {
    int xx = findset(x);
    int yy = findset(y);
    if (xx == yy) return;
    if (rand() % 2) {
        dlon[xx] = yy;
        rlon[yy] += rlon[xx];
    }
    else {
        dlon[yy] = xx;
        rlon[xx] += rlon[yy];
    }



}

/*bool cmp(rec e1, rec e2){
    return e1.w<e2.w;
}
*/





//_____________________________________________________________________________________

int main()
{




    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> lon1 >> lon2;
    for (int i = 1; i <= lon1; i++)
        dlon[i] = i;

    for (int i = 1; i <= lon2; i++) {
        cin >> lon;
        if (lon == 1) {
            cin >> G[i].v1 >> G[i].v2 >> G[i].w;
            unionset(G[i].v1, G[i].v2);
            rlon[findset(G[i].v1)] += G[i].w;
        }
        if (lon == 2) {
            cin >> lon3;
            cout << rlon[findset(lon3)] << endl;

        }

    }




    return 0;
}