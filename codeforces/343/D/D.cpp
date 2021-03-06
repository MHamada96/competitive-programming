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

const int MAX = 1 << 20;
ll cake[1 << 20][2];
ll ST[4*MAX];

void update(int node,int s,int e,int p,ll v){
	if(s == e) {
		ST[node] = v;
		return;
	}
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	if(p <= m) update(left,s,m,p,v);
	else update(right,m + 1,e,p,v);
	ST[node] = max(ST[left],ST[right]);
}

ll get(int node,int s,int e,int l,int r){
	if(l <= s && e <= r) return ST[node];
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	if(r <= m) return get(left,s,m,l,r);
	if(m < l) return get(right,m + 1,e,l,r);
	return max(get(left,s,m,l,m),get(right,m + 1,e,m + 1,r));
}

int main(){
	int n;
	ll ans = 0;
	scanf("%d",&n);
	vector<ll> V;
	V.pb(0LL);
	loop(i,n) {
		scanf("%lld %lld",&cake[i][0],&cake[i][1]);
		V.pb(cake[i][0]*cake[i][0]*cake[i][1]);
	}
	sort(all(V));
	V.resize(unique(all(V)) - V.begin());
	loop(i,n) {
		ll vol = cake[i][0]*cake[i][0]*cake[i][1];
		auto p = lower_bound(all(V),vol) - V.begin() - 1;
		ll tmp = vol + get(1,0,n,0,p);
		ans = max(ans,tmp);
		update(1,0,n,p + 1,tmp);
	}
	printf("%.9f\n",ans * PI);
	return 0;
}
