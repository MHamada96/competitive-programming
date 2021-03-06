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

const int MAX = 1e5 + 1e2;
int ST[MAX << 2],LA[MAX << 2];

void build(int node,int s ,int e ){
	ST[node] = LA[node] = 0;
	if(s == e) return ;
	int m = (s + e) >> 1,left = (node << 1) | 1,right = left + 1;
	build(left,s,m);
	build(right,m + 1,e);
}

void forward(int node,int s,int e){
	if(s == e || LA[node] == INT_MAX) return;
	int m = (s + e) >> 1,left = (node << 1) | 1,right = left + 1;
	ST[left] |= LA[node],LA[left] |= LA[node];
	ST[right] |= LA[node],LA[right] |= LA[node];
	LA[node] = 0;
}

void update(int node,int s,int e,int l,int r,int v){
	if(l <= s && e <= r){
		LA[node] |= v;
		ST[node] |= v;
		return;	
	}
	forward(node,s,e);
	int m = (s + e) >> 1,left = (node << 1) | 1,right = left + 1;
	if(r <= m) update(left,s,m,l,r,v);
	else if(m < l) update(right,m+1,e,l,r,v);
	else update(left,s,m,l,m,v),update(right,m+1,e,m+1,r,v);
	ST[node] = ST[left] & ST[right];
}

int query(int node,int s,int e,int l,int r){
	if(l <= s && e <= r) return ST[node];
	forward(node,s,e);
	int m = (s + e) >> 1,left = (node << 1) | 1,right = left + 1;
	if(r <= m) return query(left,s,m,l,r);
	else if(m < l) return query(right,m+1,e,l,r);
	else return query(left,s,m,l,m) & query(right,m+1,e,m+1,r);
}

int Q[MAX][3];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	build(0,1,n);
	loop(i,m){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		Q[i][0] = a;
		Q[i][1] = b;
		Q[i][2] = c;	
		update(0,1,n,a,b,c);
	}
	loop(i,m){
		int t = query(0,1,n,Q[i][0],Q[i][1]);
		if(t != Q[i][2]) {
			puts("NO");
			return 0;
		}
	}		
	puts("YES");
	loop(i,n) printf("%d%c",query(0,1,n,i+1,i+1)," \n"[i==n-1]);
	return 0;
}
