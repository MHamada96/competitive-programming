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

int A[1 << 20],n,idx = 0;
ll dp[1000][1000];
int mov[1000][1000];

ll solve(int pos,int rem){
	if(pos == n) return A[rem];
	if(pos == n - 1) return max(A[rem],A[pos]);
	if(dp[pos][rem] != -1) return dp[pos][rem];
	int cand[3] = {rem,pos,pos + 1};
	dp[pos][rem] = 1LL << 61;
	loop(i,3){
		int a = (i == 0) ? 1 : 0,b = 3 - a - i;
		ll tmp = solve(pos + 2,cand[i]) + max(A[cand[a]],A[cand[b]]);
		if(tmp < dp[pos][rem]){
			dp[pos][rem] = tmp;
			mov[pos][rem] = i;
		}
	}	
	return dp[pos][rem];
}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	fill(&dp[0][0],&dp[n][0],-1);
	printf("%lld\n",solve(1,0));
	int pos = 1,rem = 0;
	while(1){
		if(pos == n) {
			printf("%d\n",rem + 1);
			break;		
		}
		if(pos == n - 1){
			printf("%d %d\n",rem + 1,n);
			break;
		}
		int cand[3] = {rem,pos,pos + 1};
		int i = mov[pos][rem];
		int a = (i == 0) ? 1 : 0,b = 3 - a - i;
		printf("%d %d\n",cand[a] + 1,cand[b] + 1);
		pos += 2;
		rem = cand[i];
	}
	return 0;
}
