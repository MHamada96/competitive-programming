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

int A[4000],n;
int B[4000],m;
vi C[4000];
int dp[4000][4000];

int solve(int p,int prev){
	if(dp[p][prev] != -1) return dp[p][prev];
	dp[p][prev] = 1;
	int q = upper_bound(all(C[prev]),p) - C[prev].begin();
	if(q != sz(C[prev]) && p < C[prev][q]) {
//		fprintf(stderr,"(%d,%d) -> (%d,%d)\n",p,A[p],C[prev][q],prev);			
		dp[p][prev] += solve(C[prev][q],A[p]);
	}
	return dp[p][prev];
}

int main(){
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i),B[i] = A[i];
	sort(B,B + n);
	m = unique(B,B + n) - B;
	loop(i,n) A[i] = lower_bound(B,B + m,A[i]) - B,C[A[i]].pb(i);
	//prArr(A,n,int);
	int ans = 0;
	loop(i,n) loop(j,m) ans = max(ans,solve(i,j));
	printf("%d\n",ans);
	return 0;
}
