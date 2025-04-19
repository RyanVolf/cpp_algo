#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int DIM = 100007;
const int INF = 1000000007;

struct Event{
    long long x, type;
};


Event a[100007];
bool cmp(Event p1, Event p2)
{
    if(p1.x== p2.x){
        return p1.type>p2.type;
    }
    else {
        return p1.x<p2.x;


    }




}

;


long long  x,L,R,doublon[1007][1007],lich,mpl,mni1,mni2,mni3,mni4, mm,mni,mmi,rlon[DIM], rlon1[DIM],rlon2[DIM],rlon3[DIM],rlon4[DIM], lon, lon1,maxi1,mini1, lon2,pl, lon3,lon4,lon5,lon6,lon7 ,lon8,mini, start, finish, maxi, dlon[DIM],dlon1[DIM], have, need;
char ch, ch1, ch2,ch3,ch4, dch[DIM];
string str, str1, str2,str3, str4, str5,str6, str7,ss,ss1,ss2,istr[DIM];
int in, in1, in2, in3;
set <char> sch;
set <long long> slon;
set <string> sstr;
map<string, long long> m;
long double lond,lond1, dlond[DIM],lond2,lond3,lond4;
int y;

int findset(int x){
    if(dlon[x]==x)  return x;
    else return dlon[x]=findset(dlon[x]);

}

void unionset(int x, int y) {
    int xx,yy;
    xx = findset(x);
    yy = findset(y);
    if(rand() % 2 == 0)
        dlon[xx] = yy;
    else
        dlon[yy] = xx;
}




bool check(int x, int y){
        return findset(x)==findset(y);
}


void setreset(int n){
    for(int i=0; i<n; i++)
        dlon[i]=i;

}


//_____________________________________________________________________________________

int main()
{




    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin>>str){
        if(str=="RESET"){
            cin>>lon1;
            setreset(lon1);
            cout<<"RESET DONE"<<endl;
        }
        if(str=="JOIN"){
            cin>>x>>y;
            if(check(x,y)) cout<<"ALREADY "<<x<<" "<<y<<endl;
            unionset(x,y);

        }
        if(str=="CHECK"){
            cin>>x>>y;
            if(check(x,y)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

        }
    }





return 0;
}