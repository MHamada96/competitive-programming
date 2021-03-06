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

const int MAX = 1024;
pair<pi,int> req[MAX];
int n,k;
pi table[MAX];
int dp[MAX][MAX];
int nxt[MAX][MAX];
int solve(int p1 = 0,int p2 = 0){
	if(p1 == n || p2 == k) return 0;
	if(dp[p1][p2] != -1) return dp[p1][p2];
	int & ans = dp[p1][p2];
	ans = solve(p1 + 1,p2 + 1) + ((req[p1].xx.xx <= table[p2].xx) ? req[p1].xx.yy : 0);
	nxt[p1][p2] = 3;
	if(solve(p1,p2 + 1) > ans) {
		ans = solve(p1,p2 + 1);
		nxt[p1][p2] = 2;
	}
	
	if(solve(p1 + 1,p2) > ans) {
		ans = solve(p1 + 1,p2);
		nxt[p1][p2] = 1;
	}
	return ans;
}

int main(){
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	loop(i,n) scanf("%d %d",&req[i].xx.xx,&req[i].xx.yy),req[i].yy = i;
	sort(req,req + n);
	scanf("%d",&k);
	loop(i,k) scanf("%d",&table[i].xx),table[i].yy = i;
	sort(table,table + k);
	cerr << solve() << endl;
	int ans = solve();
	vp V;	
	int s = 0,e = 0;
	while(s < n && e < k){
		if(nxt[s][e] == 3 && req[s].xx.xx <= table[e].xx) V.pb({req[s].yy + 1,table[e].yy + 1});
		int t = nxt[s][e];
		s += t & 1;
		e += (t >> 1) & 1;
	}
	printf("%d %d\n",sz(V),ans);
	for(auto p : V) printf("%d %d\n",p.xx,p.yy);
	return 0;
}
