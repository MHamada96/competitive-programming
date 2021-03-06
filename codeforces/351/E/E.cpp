#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define vi vector<int>
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
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

double dp[51][200001];
double S[200001],T[200001],ST[200001];
int Q[200001];
int n,m;

inline double gg(int s,int e){
	if(e == s + 1) return 1;
	return ST[e] - ST[s] - S[s]*(T[e] - T[s]);
}

inline double g(point a,point b){
	return (b.yy - a.yy) / (a.xx - b.xx);
}

inline double f(point x,int i){
	return x.xx * T[i] + x.yy + ST[i];
}

inline double cmp(double x,double y){
	return (fabs(x - y) < 1e-8) || (x < y);
}

int main(){
	scanf("%d %d",&n,&m);
	loop(i,n) scanf("%d",Q + i + 1);
	loop(i,n){
		S[i + 1] = S[i] + Q[i + 1];
		T[i + 1] = T[i] + 1.0/Q[i + 1];
		ST[i + 1] = ST[i] + S[i + 1]/Q[i + 1];
	}
	range(i,1,n) dp[0][i] = gg(0,i);
	//prArr(dp[0],n + 1,double);
	range(k,1,m - 1){
		deque<pair<double,double> > dq;
		dq.pb(mp(0,0));
		range(i,1,n){
			// insert dp[k - 1][i]
			double a = - S[i],b = -ST[i] + S[i] * T[i] + dp[k - 1][i];
			point tmp = mp(a,b);
			while(sz(dq) > 1 && cmp(g(dq[sz(dq) - 2],tmp),g(dq[sz(dq) - 2],dq[sz(dq) - 1]))) dq.pop_back();
			dq.pb(tmp);
			while(sz(dq) > 1 && cmp(f(dq[1],i),f(dq[0],i))) dq.pop_front();
			dp[k][i] = f(dq[0],i);					
		}
	//	prArr(dp[k],n + 1,double);
	}
	printf("%.9f\n",dp[m - 1][n]);
	return 0;
}
