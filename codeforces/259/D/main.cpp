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

vi P{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int n,m = sz(P);
const int INF = 1 << 29;
int A[100];
int dp[100][1 << 17];
int content[60],nxt[100][1 << 17];

void init(){
	range(a,1,59){
		int msk = 0;		
		loop(i,m) if(a%P[i] == 0) msk |= 1 << i;
		content[a] = msk;
	}
	memset(dp,-1,sizeof dp);
}

int solve(int pos = 0,int msk = (1 << 17)-1){
	if(pos == n) return 0;
	int & ret = dp[pos][msk];
	if(ret != -1) return ret;
	ret = INF;
	range(a,1,59) if(content[a] == (content[a] & msk)){
		int tmp = solve(pos + 1,msk ^ content[a]) + abs(a - A[pos]);
		if(tmp < ret){
			ret = tmp;
			nxt[pos][msk] = a;
		}
	}
	return ret;
}

int main(){
	init();		
cerr << "done init" << endl;
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	solve();
	int pos = 0,msk = (1 << 17) - 1;
	while(pos < n){
		int a = nxt[pos][msk];
		A[pos] = a;		
		pos ++;
		msk ^= content[a];
	}
	loop(i,n) printf("%d%c",A[i]," \n"[i == n - 1]);
	return 0;
}
