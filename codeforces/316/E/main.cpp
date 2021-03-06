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

const int mod = 1e9 + 7;

struct node{
	int x,y,idx;
	char c;
	int LC,RC,LP,RP;
public:
	node():LC(0),RC(0),LP(0),RP(0){}
	node(int x,int y,char c):x(x),y(y),c(c),RC(0),LP(0),RP(0){}
};

node G[10000];
char M[500][510];
int dp[10000][10000];
int m,n;


void pr(node & g){
	cout << "node #" << g.idx << " with char " << g.c << " @(" << g.x << " ," << g.y << ") parents are " << g.LP << " " << g.RP
		<< " children are " << g.LC << " " << g.RC << endl; 
}

void build(){
	G[0].c = 0;
	loop(i,m) loop(j,n) {int idx = i * n + j + 1;G[idx].idx = idx;}
	loop(i,m) loop(j,n) {
		int idx = i * n + j + 1;
		G[idx].x = i;
		G[idx].y = j;
		G[idx].c = M[i][j];	
		if(i < m - 1) G[idx].LC = G[(i + 1) *n + j + 1].idx;
		if(j < n - 1) G[idx].RC = G[i * n + j + 1 + 1].idx;
		if(i) G[idx].LP = G[(i - 1) * n +  j + 1].idx;
		if(j) G[idx].RP = G[i * n +  (j - 1) + 1].idx;	
	//	pr(G[idx]);	
	}
}

int solve(int i,int j,int d){
	if(d > m + n - 1) return 0;
	if(i == j) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	if(abs(G[i].x - G[j].x) + abs(G[i].y - G[j].y) == 1) dp[i][j]++;
	if(G[G[i].LC].c == G[G[j].LP].c) dp[i][j] = (dp[i][j] + solve(G[i].LC,G[j].LP,d + 2))%mod;
	if(G[G[i].LC].c == G[G[j].RP].c) dp[i][j] = (dp[i][j] + solve(G[i].LC,G[j].RP,d + 2))%mod;
	if(G[G[i].RC].c == G[G[j].LP].c) dp[i][j] = (dp[i][j] + solve(G[i].RC,G[j].LP,d + 2))%mod;
	if(G[G[	i].RC].c == G[G[j].RP].c) dp[i][j] = (dp[i][j] + solve(G[i].RC,G[j].RP,d + 2))%mod;
	return dp[i][j] %= mod;
}

int main(){
	scanf("%d %d",&m,&n);
	fill(&dp[0][0],&dp[m * n + 1][0],-1);	
	loop(i,m) scanf("%s",M[i]);
	if(m * n == 1){
		cout << 1 << endl;
		return 0;
	}
	build();
	cout << solve(1,m * n,2) << endl;
	return 0;
}

