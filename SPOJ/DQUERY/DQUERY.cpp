#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define vi vector<int>
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
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

int n,A[30000],m;
pair<pi,pi> event[30000 + 200000];
int ans[200000];
int BIT[30001],MAP[1 << 20];

void update(int p,int v){
	for(;p <= 30000;p += LSOne(p)) BIT[p] += v;
}
int query(int p){
	int ret = 0;
	for(;p;p -= LSOne(p)) ret += BIT[p];
	return ret;
}

int main(){
	scanf("%d",&n);
	loop(i,n) {
		scanf("%d",A + i);
		event[i] = mp(mp(i + 1,0),mp(0,0));
	}
	scanf("%d",&m);
	loop(i,m){
		scanf("%d %d",&event[i + n].yy.xx,&event[i + n].xx.xx);
		event[i + n].xx.yy = 1;
		event[i + n].yy.yy = i;
	}
	sort(event,event + n + m);
	loop(i,n + m){
		if(event[i].xx.yy){
			int s = event[i].yy.xx,e = event[i].xx.xx,j = event[i].yy.yy;
			ans[j] = query(e) - query(s - 1);
		//	cerr << j << " " << s << " " << e << " " << ans[j] << endl;
		}
		else{
			int j = event[i].xx.xx;
			if(MAP[A[j - 1]]) update(MAP[A[j - 1]],-1);
			update(j,1);
			MAP[A[j - 1]] = j;
		//	cerr << A[j - 1] << " " << j << endl;
		}
	}
	loop(i,m) printf("%d\n",ans[i]);
	return 0;
}
