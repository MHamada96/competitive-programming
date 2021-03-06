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
const int oo = 1 << 29;
int dp[MAX][MAX][2],m,n,colCnt[MAX][2],x,y;
char G[MAX][MAX];

int solve(int col,int run,int last_color){
	if(run > y) return oo;
	if(col == n) return (run >= x) ? 0 : oo;
	int & ans = dp[col][run][last_color];
	if(ans != -1) return ans;
	ans = solve(col + 1,run + 1,last_color) + colCnt[col][last_color ^ 1];
	if(run >= x) ans = min(ans,solve(col + 1,1,last_color ^ 1) + colCnt[col][last_color]);
	return ans;
}

int main(){
	memset(dp,-1,sizeof dp);
	scanf("%d %d %d %d",&m,&n,&x,&y);
	loop(i,m) scanf("%s",G[i]);
	loop(col,n) loop(row,m) colCnt[col][G[row][col] == '#']++;
	cout << min(solve(0,0,0),solve(0,0,1)) << endl;
	return 0;
}
