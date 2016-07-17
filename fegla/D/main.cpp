#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
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

const ll mod = 1e9 + 7;

int N,H,W;
int A[1000];
ll dp[1000];

ll f(int p){
	if(p >= W) return p == W;
	if(dp[p] != -1) return dp[p];
	dp[p] = 0;	
	loop(i,N) {
		if(p + A[i] == W) dp[p] = (dp[p] + 1)%mod;
		else if(p + A[i] != W - 1) dp[p] = (dp[p] + f(p + A[i] + 1))%mod; 
	}
	return dp[p];
}

ll EXP(ll p,int q){
	ll a = p,b = 1;
	while(q > 1){
			if(q & 1) b = (a * b)%mod;
			a = (a*a)%mod;
			q >>= 1;
	}
	return (a*b)%mod;
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&N,&H,&W);
		fill(dp,dp + W,-1);
		loop(i,N) scanf("%d",A + i);
		ll ans = f(0);
		ans = EXP(ans,H);
		printf("%lld\n",ans);
	}
	return 0;
}
