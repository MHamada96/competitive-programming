#include<iostream>
#include<map>
#include<deque>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
int main()
{
map<pair<int,int>,int> m;
deque<pair<int,int> > v;
int x0,x1,y0,y1,n,r[100005],a[100005],b[100005],i,j,x[]={-1,-1,-1,0,0,1,1,1},y[]={-1,0,1,-1,1,-1,0,1};
cin>>x0>>y0>>x1>>y1>>n;
for(i=1;i<=n;i++)
{
cin>>r[i]>>a[i]>>b[i];
for(j=a[i];j<=b[i];j++) m[mp(r[i],j)]=-1;
}
m[mp(x0,y0)]=1;
v.pb(mp(x0,y0));
while(v.size())
{
x0=v[0].F;
y0=v[0].S;
v.pop_front();
for(i=0;i<8;i++)
{
if(m[mp(x0+x[i],y0+y[i])]<0)
{
m[mp(x0+x[i],y0+y[i])]=m[mp(x0,y0)]+1;
v.pb(mp(x0+x[i],y0+y[i]));
}
}
}
if(m[mp(x1,y1)]<0) cout<<-1;
else cout<<m[mp(x1,y1)]-1;
cout << endl;
return 0;
}
