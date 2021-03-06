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

double dp[1001][1001][2];

double solve(int w,int b,int turn){
	if(w == 0) return 0;
	if(b == 0) return turn == 1;
	double & ans = dp[w][b][turn];
	if(ans == ans) return ans;
	if(turn) return ans = w/(w + b + 0.0) + b/(w + b + 0.0) * solve(w,b - 1,0);
	ans = w/(w + b - 1.0) * solve(w - 1,b - 1,1) ;
	if(b >= 2) ans += (b - 1)/(w + b - 1.0) * solve(w,b - 2,1);
	return ans *= b/(w + b + 0.0);
}

int main(){
	memset(dp,-1,sizeof dp);
	int w,b;
	cin >> w >> b;
	printf("%.9f\n",solve(w,b,1));
	return 0;
}
