#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define print(A,t) cout << #A << ": "; copy(all(A),ostream_iterator<t>(cout," " )); cout << endl
#define pi pair<int,int>
#define point pi
#define vi vector<int>
#define ll long long
#define pl pair<ll,ll>
#define pre() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)
using namespace std;


pl P[1 << 20]; int N;
int vis[1 << 20];

ll dist2(pl & u,pl & v){
	return (u.first - v.first)*(u.first - v.first) + (u.second - v.second)*(u.second - v.second);
}

bool f(ll x){
	fill(vis,vis + N,0);
	int ctr = 0;
	loop(i,N)
		if(!vis[i]){
			if(ctr == 3) return 0;
			++ctr;
			for(int j = i;j < N;j++)
				if(!vis[j] && dist2(P[i],P[j]) <= x*2LL*x) 
					vis[j] = 1;		
		}
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		loop(i,N) scanf("%lld %lld",&P[i].first,&P[i].second);
		ll u = 0,v = INT_MAX;
		while(u < v){
			ll m = (u + v + 1) >> 1;
			if(f(m)) v = m - 1;
			else u = m;
		}
		u += !f(u);
		printf("%lld\n",u );
	}
	return 0;
}
