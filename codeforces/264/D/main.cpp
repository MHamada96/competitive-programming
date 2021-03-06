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

int dp[1001];
int inv[5][1001],n,k,a;

int solve(int a){
	if(dp[a] != -1) return dp[a];
	dp[a] = 1;	
	range(b,1,n){
		bool c = 1;
		loop(i,k) c &= inv[i][b] > inv[i][a];
		if(c) dp[a] = max(dp[a],solve(b) + 1);
	}	
	return dp[a];
}


int main(){
	fill(dp,dp + 1001,-1);
	scanf("%d %d",&n,&k);
	loop(i,k) {
		loop(j,n) {
			scanf("%d",&a);
			inv[i][a] = j;
		}
	}
	int ans = 0;
	range(i,1,n) ans = max(ans,solve(i));
	cout << ans << endl;
	return 0;
}
