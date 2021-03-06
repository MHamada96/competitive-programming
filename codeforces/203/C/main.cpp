#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,L = (n);i < L;i++)
#define range(i,a,b) for(int i = (a),L = (b);i <= L;i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
#define vp vector<pair<int,int> >
#define ll long long
#define pi pair<int,int>
#define point pair<double,double>
#define pl pair<ll,ll>
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

int n,ans = 0;
pi P[1 << 20];

void prmov(int c,int d){
	if(c == 0) return ;
	char o;
	if(c < 0) o = d ? 'D' : 'L';
	else o = d ? 'U' : 'R';
	printf("1 %d %c\n",abs(c),o);
}

#define dist(a) (abs(a.xx) + abs(a.yy))

bool cmp(const pi & a,const pi & b){
	if(dist(a) != dist(b)) return dist(a) < dist(b);
	return a < b;
}

int main(){
	scanf("%d",&n); ans = 2*n;
	loop(i,n) scanf("%d %d",&P[i].xx,&P[i].yy),ans += 2*(P[i].xx != 0) + 2*(P[i].yy != 0);
	sort(P,P + n,&cmp);
	printf("%d\n",ans);
	loop(i,n){
		prmov(P[i].xx,0);		
		prmov(P[i].yy,1);		
		puts("2");
		prmov(-P[i].xx,0);		
		prmov(-P[i].yy,1);		
		puts("3");
	}
	return 0;
}
