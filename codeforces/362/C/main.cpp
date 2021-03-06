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

map<pl,ll> W;

int level(ll u){
	int l = 0;
	while(u){
		l++;
		u >>= 1;
	}
	return l;
}

ll get_path(ll u,ll v){
	ll ret = 0;
	if(u > v) swap(u,v);
	int l1 = level(u),l2 = level(v);
	while(l1 < l2) {
		ll p = v/2;
		if(W.find(mp(p,v)) != W.end()) ret += W[mp(p,v)];
		v = p;
		l2--;
	}
	while(u != v){
		ll p = v/2;
		if(W.find(mp(p,v)) != W.end()) ret += W[mp(p,v)];
		p = u/2;
		if(W.find(mp(p,u)) != W.end()) ret += W[mp(p,u)];
		u >>= 1,v >>= 1;
	}
	return ret;
}


void update(ll u,ll v,int w){
	if(u > v) swap(u,v);
	int l1 = level(u),l2 = level(v);
	while(l1 < l2) {
		ll p = v/2;
		if(W.find(mp(p,v)) == W.end()) W[mp(p,v)] = 0;
		W[mp(p,v)] += w;
		v = p;
		l2--;
	}
	while(u != v){
		ll p = v/2;
		if(W.find(mp(p,v)) == W.end()) W[mp(p,v)] = 0;
		W[mp(p,v)] += w;
		p = u/2;
		if(W.find(mp(p,u)) == W.end()) W[mp(p,u)] = 0;
		W[mp(p,u)] += w;
		u >>= 1,v >>= 1;
	}
}

int main(){
	int T; ll u,v;
	int q,w;
	scanf("%d",&T);
	while(T--){
		scanf("%d %I64d %I64d",&q,&u,&v);
		if(q == 1){
			scanf("%d",&w);
			update(u,v,w);
		}
		else printf("%I64d\n",get_path(u,v));
	}
	return 0;
}
