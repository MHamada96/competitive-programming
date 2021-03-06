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

const int MAX = 1e5;
vi G[MAX];
pi dp[MAX][10];
int T,n;
char line[MAX];	

int dfs0(int p){
	if(line[p] == '0') return p;
	if(line[p] == '1'){
		G[p].pb(p + 1);
		return dfs0(p + 1);
	}
	G[p].pb(p + 1);
	int q = dfs0(p + 1) + 1;
	G[p].pb(q);
	return dfs0(q);
}

pi dfs1(int u,int msk){	
	if(sz(G[u]) == 0) return mp(msk == 1,msk & 1);	
	if(dp[u][msk].xx != -1) return dp[u][msk];
	int x = 1 << 29,y = 0;	
	loop(color,3){
		if(msk & (1 << color)){
			int nmsk = 7 ^ (1 << color);
			if(sz(G[u]) == 1){
				pi tmp = dfs1(G[u][0],nmsk);
				x = min(x,tmp.xx + (color == 0));
				y = max(y,tmp.yy + (color == 0));
			}
			else{
				int one = -1,other;
				loop(oc,3){
					if(nmsk & (1 << oc)){
						if(one == -1) one = 1 << oc;
						else other = 1 << oc;
					}
				}
				pi tmp1 = dfs1(G[u][0],one),tmp2 = dfs1(G[u][1],other);
				x = min(x,tmp1.xx + tmp2.xx + (color == 0));
				y = max(y,tmp1.yy + tmp2.yy + (color == 0));
				tmp1 = dfs1(G[u][1],one),tmp2 = dfs1(G[u][0],other);
				x = min(x,tmp1.xx + tmp2.xx + (color == 0));
				y = max(y,tmp1.yy + tmp2.yy + (color == 0));
			}
		}
	}
	return dp[u][msk] = mp(x,y);
}


int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",line);
		n = strlen(line);
		fill(&dp[0][0],&dp[n][0],mp(-1,-1));
		loop(i,n) G[i].clear();			
		dfs0(0);		
		pi tmp = dfs1(0,7);
		printf("%d %d\n",tmp.yy,tmp.xx);
	}
	return 0;
}
