#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,_ = (n);i < _;i++)
#define range(i,a,b) for(int i = (a),_ = (b);i <= _;i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b),_ = (a);i >= _;i--)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
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

const int MAX = 100000;
vi P;
int not_p[MAX],A[MAX],n,pos[MAX];

void sieve(){
	for(ll i = 2;i < MAX;i++){
		if(not_p[i]) continue;
		P.pb((int)i);
		for(ll j = i*i;j < MAX;j += i)
			not_p[j] = 1;
	}
}

int main(){
	sieve();
	scanf("%d",&n);
	loop(i,n) scanf("%d",&A[i]),pos[--A[i]] = i;
	vector<pi> out;
	loop(i,n) {
		while(i != pos[i]){
			auto q = upper_bound(all(P),pos[i] - i + 1);
			int p = *--q;
			int u = pos[i],v = pos[i] - p + 1,x = i,y = A[v];			
			swap(A[u],A[v]);
			pos[x] = v;
			pos[y] = u;
			if(v < u) swap(u,v);
			out.pb(mp(u + 1,v + 1));
		}
	}
	printf("%lu\n",sz(out));
	for(auto p : out) printf("%d %d\n",p.xx,p.yy);
	return 0;
}
