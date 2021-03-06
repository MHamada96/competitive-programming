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
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define prp(p) cout << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cout << #A << ": "; copy(A,A + n,ostream_iterator<t>(cout," " )); cout << endl
using namespace std;

const int MAX = 100000 + 1;
const ll mod = 1e9 + 7;
ll dp[301][MAX];
ll  S[301][MAX];
ll F[MAX];
int main(){
	F[0] = 1;
	loop(i,MAX - 1) F[i + 1] = (F[i] * (i + 1))%mod;
	for(int n = 1;n <= 300;n++){
		for(int k = 1;k <= 100000;k++){
			if(n == 1) dp[n][k] = 1;
			else{
				//for(int i = 1;i <= k/n;i++) dp[n][k] += dp[n - 1][k - i*n];
				//k - i*n
				if(k >= n) dp[n][k] = S[n - 1][k - n];	
				else dp[n][k] = 0;		
			}
			S[n][k] = dp[n][k];
			if(k >= n + 1) {
				S[n][k] += S[n][k - n - 1];
				if(S[n][k] >= mod) S[n][k] -= mod;	
			}
			//if(n <= 10 && k <= 50) printf("%lld ",dp[n][k]);
		}
		//if(n <= 10) puts("");
	}
	int T,N,K;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&K);
		ll ans = (F[N] * dp[N][K])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
