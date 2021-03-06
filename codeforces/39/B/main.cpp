#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
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

int n,A[100];
int dp[100][101],nxt[100][101];

int solve(int p,int to){
	if(p == n) return 0;
	if(dp[p][to] != -1) return dp[p][to];
	dp[p][to] = solve(p + 1,to);
	nxt[p][to] = 0;
	if(A[p] == to) {
		int tmp = solve(p + 1,to + 1) + 1;
		if(tmp > dp[p][to]){
			dp[p][to] = tmp;
			nxt[p][to] = 1;
		}
	}
	return dp[p][to];
}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	memset(dp,-1,sizeof dp);
	printf("%d\n",solve(0,1));	
	int p = 0,to = 1;
	while(p != n){
		if(nxt[p][to]) printf("%d ",2000+p+1),to++;
		p++;
	}
	return 0;
}
