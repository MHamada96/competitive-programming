#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,_ = (n);i < _;i++)
#define range(i,a,b) for(int i = (a),_ = (b);i <= _;i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b),_ = (a);i >= _;i--)
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
 
int m,n,a,b;
int A[1000][1000];
ll  S[1000][1000];
int RMQ[1000][1000][10][10];
int lg[1000];


void init(){
	loop(i,m) loop(j,n){
		S[i][j] = A[i][j];
		if(i) S[i][j] += S[i - 1][j];
		if(j) S[i][j] += S[i][j - 1];
		if(i && j) S[i][j] -= S[i - 1][j - 1];
	}
	lg[0] = -1;
	loop(i,999){
		int j = i + 1;
		lg[j] = lg[i] + (j == LSOne(j));
	}
	loop(i,m) loop(j,n) RMQ[i][j][0][0] = A[i][j];
	loop(k1,9) {
		int o1 = k1 ? (1 << (k1 - 1)) : 0;		
		int j1 = max(k1 - 1,0);
		loop(k2,9) {
			int o2 = k2 ? (1 << (k2 - 1)) : 0;
			int j2 = max(k2 - 1,0);
			loop(i,m) loop(j,n){
				int & mx = RMQ[i][j][k1][k2];
				mx = RMQ[i][j][j1][j2];
				if(i + o1 < m) mx = max(mx,RMQ[i + o1][j][j1][j2]);
				if(j + o2 < n) mx = max(mx,RMQ[i][j + o2][j1][j2]);
				if(i + o1 < m && j + o2 < n) mx = max(mx,RMQ[i + o1][j + o2][j1][j2]);
			}
		}
	}
	
	//loop(i,m) loop(j,n) loop(k1,8){
	//	cerr << i << " " << j << " " << k1 << " -> ";
	//	prArr(RMQ[i][j][k1],8,int);
	//}
	
}


int main(){
	scanf("%d %d",&m,&n);
	loop(i,m) loop(j,n) scanf("%d",&A[i][j]);
	init();
	int Q;
	scanf("%d",&Q);
	loop(i,Q) {
		int x,y,lx,ly; ll ans = LLONG_MAX;
		scanf("%d %d",&x,&y);
		lx = lg[x],ly = lg[y];
		loop(i,m - x + 1) loop(j,n - y + 1){
			ll sum = S[i + x - 1][j + y - 1];
			if(i) sum -= S[i - 1][j + y - 1];
			if(j) sum -= S[i + x - 1][j - 1];
			if(i && j) sum += S[i - 1][j - 1];
			
			int mx = RMQ[i][j][lx][ly];
			mx = max(mx,RMQ[i + x - (1 << lx)][j][lx][ly]);
			mx = max(mx,RMQ[i][j + y - (1 << ly)][lx][ly]);
			mx = max(mx,RMQ[i + x - (1 << lx)][j + y - (1 << ly)][lx][ly]);
			ans = min(ans,x*1LL*mx*1LL*y - sum);
		//	cerr << mx << " " << sum << endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
 
/*
1 8 3 4
5 2 3 1
3 6 2 2
*/ 
