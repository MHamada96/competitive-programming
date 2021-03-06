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

int dp[200];
char line[210];
int n,T;

int solve(int p){
	if(p == n) return 0;
	if(dp[p] != -1) return dp[p];
	dp[p] = 0; int sweet = 0,soar = 0;
	for(int e = p;e < n;e++) {
		sweet += line[e] == '1';
		soar += line[e] == '0';
		dp[p] = max(dp[p],solve(e + 1) + (sweet > soar)*(e - p + 1));
	}
	return dp[p];
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,line);
		fill(dp,dp + n,-1);
		printf("%d\n",solve(0));
	}
	return 0;
}
