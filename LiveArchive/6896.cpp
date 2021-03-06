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

int dp[1 << 10][4];

int solve(int x,int y){
	if(x == 0) return y == 0;
	if(y == 0) return 0;
	if(x < 0) return 0;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for(int i = 1;i*(i + 1) <= (x << 1);i++)
		dp[x][y] |= solve(x - ((i * (i + 1))>>1),y - 1);
	return dp[x][y]; 
}

int main(){
	fill(&dp[0][0],&dp[1 << 10][0],-1);
	int T,X;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&X);
		printf("%d\n",solve(X,3));
	}
	return 0;
}
