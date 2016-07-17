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

const int MAX = 2e5;
ll BIT[MAX]; int n,m;
ll B[MAX],P,V[MAX];


void update(int p,ll v){for(;p <= m;p += LSOne(p)) BIT[p] += v;}
ll get(int p){
	if(p < 0) return 0;
	ll ret = 0;
	for(;p;p -= LSOne(p)) ret += BIT[p];
	return ret;
}

int main(){
	int T; ll ans = 0;
	scanf("%d",&T);
	loop(t,T){
		ans = 0;
		scanf("%d %lld",&n,&P);
		loop(i,n) {
			scanf("%lld",B + i);
			if(i) B[i] += B[i - 1];
			V[i] = B[i];
		}
		V[n] = 0,V[n + 1] = P;
		sort(V,V + n + 2); m = unique(V,V + n + 2) - V;
		fill(BIT,BIT + m + 2,0);
		update(1,1);		
		loop(i,n){
			ll v = B[i] - P;
			v = lower_bound(V,V + m,v) - V;
			ans += get(m) - get(v);
			v = lower_bound(V,V + m,B[i]) - V + 1;
			update(v,1);
		}
		printf("Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}
