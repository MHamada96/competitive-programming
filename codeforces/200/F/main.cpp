#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
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

const int MAX = 600000;

vi G[MAX];
int P[MAX],inTime[MAX],outTime[MAX],n;
int ST[MAX << 2],LA[MAX << 2],idx;

void dfs(int u,int p){
	P[u] = p;
	inTime[u] = idx++;
	for(int v : G[u]) if (v != p) dfs(v,u);
	outTime[u] = idx - 1;
}

void update(int node,int s,int e,int l,int r,int v){
	if(l <= s && e <= r) {
		ST[node] = LA[node] = v;
		return ;
	}
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	if(LA[node]) {
		LA[left] = LA[right] = ST[left] = ST[right] = 1;
		LA[node] = 0;
	}
	if(r <= m) update(left,s,m,l,r,v);
	else if(m < l) update(right,m+1,e,l,r,v);
	else update(left,s,m,l,m,v),update(right,m+1,e,m+1,r,v);
	ST[node] = min(ST[left],ST[right]);
}

int get(int node,int s,int e,int l,int r){
	if(l <= s && e <= r) return ST[node];
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	if(LA[node]) {
		LA[left] = LA[right] = ST[left] = ST[right] = 1;
		LA[node] = 0;
	}
	if(r <= m) return get(left,s,m,l,r);
	if(m <  l) return get(right,m + 1,e,l,r);
	return min(get(left,s,m,l,m),get(right,m+1,e,m+1,r));
}

int main(){
	int a,b;
	scanf("%d",&n);
	loop(i,n - 1){
		scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1,0);
	int m;
	scanf("%d",&m);
	range(i,1,m){
		scanf("%d %d",&a,&b);
		if(a == 1) {
			int q = get(1,0,n-1,inTime[b],outTime[b]);
			if(!q && P[b]) update(1,0,n-1,inTime[P[b]],inTime[P[b]],0);
			update(1,0,n-1,inTime[b],outTime[b],1);
		}
		else if(a == 2) update(1,0,n-1,inTime[b],inTime[b],0);
		else printf("%d\n",get(1,0,n-1,inTime[b],outTime[b]));
		//prArr(LA + 1,(n << 1),int);
		//prArr(ST + 1,(n << 1),int);
		//cerr << endl;
	}
	return 0;
}
