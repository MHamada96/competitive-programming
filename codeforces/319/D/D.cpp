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

int n,P[1 << 20],V[1 << 20],connected[1 << 20];
set<int> G[1 << 20];

bool check(int a,int b){
	a = P[a],b = P[b];
	return G[a].find(b) != G[a].end() || G[b].find(a) != G[b].end();
}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",P + i),P[i]--;
	vi C;
	loop(i,n) if(V[i] == 0){
		if(P[i] == i){
			C.clear();
			C.pb(i);
			V[i] = 1;
			continue;
		} 
		int u = i,l = 0;
		while(!V[u]){
			V[u] = 1;
			u = P[u];
			l++;
		}
		if(l == 2 && C.empty()){
			C.pb(i);
			C.pb(P[i]);
		}
	}
	vector<pi> E;
	if(sz(C) == 0) puts("NO");
	else {
		int c1 = C[0],c2 = (sz(C) == 1) ? c1 : C[1];
		if(sz(C) == 2) E.pb(mp(C[0],C[1])),G[C[0]].insert(C[1]);		
		loop(i,n) if(i != c1 && i != c2){
			int u = i;
			while(!connected[u]){
				connected[u] = 1;
				G[c1].insert(u);
				E.pb(mp(c1,u));
				u = P[u];
				swap(c1,c2);
			}
		}
		if(sz(E) != n - 1) puts("NO");
		else{
			for(auto e : E) if(!check(e.xx,e.yy)) {
				cerr << e.xx << " " << e.yy << endl;
				puts("NO");
				return 0;
			}
			puts("YES");
			for(auto e : E) printf("%d %d\n",e.xx + 1,e.yy + 1);
		}
	}
	return 0;
}
