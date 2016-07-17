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

string input[600];
int ord[600]; ll dp[600][600];
int T, N,K;

int f(string & u,string & v){
	int i = 0;
	while(i < len(u) && i < len(v) && u[i] == v[i]) i++;
	return len(u) - i + len(v) - i + 1;
}

ll solve(int n,int k){
	if(k == 0) return len(input[ord[n]]);
	if(dp[n][k] != -1) return dp[n][k];
	dp[n][k] = 1LL << 62;
	for(int j = n + 1;j <= N;j++) dp[n][k] = min(dp[n][k],f(input[ord[n]],input[ord[j]]) + solve(j,k - 1));
	return dp[n][k];
}

bool cmp(const int & a,const int & b){
	return input[a] < input[b];
}

int main(){
	scanf("%d",&T);
	loop(t,T){
		scanf("%d %d",&N,&K);
		range(i,1,N) cin >> input[i],ord[i] = i;
		sort(ord + 1,ord + N + 1,&cmp);
		loop(i,N + 1) loop(j,K + 1) dp[i][j] = -1;
		printf("Case #%d: %lld\n",t + 1,solve(0,K));
	}	
	return 0;
}
