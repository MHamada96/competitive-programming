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


int dp[100][100][100];
int X[100][100][100];
int Y[100][100][100];

int solve(int a,int b,int c){
	if(a == 0 && b == 0 && c == 1) return 0;
	int & ans = dp[a][b][c];		
	if(ans != -1) return ans;
	ans = 0;
	loop(i,a) if(!solve(i,b,c)) {X[a][b][c] = 0; Y[a][b][c] = i; return ans = 1;}
	loop(i,b) if(!solve(min(a,i),i,c)) {X[a][b][c] = 1; Y[a][b][c] = i; return ans = 1;}
	range(i,1,c - 1) if(!solve(min(a,i),min(b,i),i)) {X[a][b][c] = 2; Y[a][b][c] = i; return ans = 1;}
	return ans;
}

int main(){
	fill(&dp[0][0][0],&dp[100][0][0],-1);
	int T,K,a,b,c;
	scanf("%d",&T);	
	while(T--){
		scanf("%d %d %d %d",&K,&c,&b,&a);		
		if(solve(a,b,c)) printf("%d W %d %d\n",K,X[a][b][c] + 1,Y[a][b][c] + 1);
		else printf("%d L\n",K);
	}
	return 0;
}
