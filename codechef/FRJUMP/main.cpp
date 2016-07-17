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


int mod = 1e9 + 7;

vi PathsIBelongTo[1 << 20];
int TOT[1 << 20];
double q[1 << 20];
double lg[1 << 20];
int A[1 << 20],n,m;

void init(){
	fill(TOT,TOT + n + 1,1);
	range(r,1,n){
		int p = 0;
		while(p < n){
			if(p) {
				TOT[r] = (TOT[r] * 1LL * A[p])%mod;
				q[r] += lg[p];
				PathsIBelongTo[p].pb(r);
			}
			p += r;
		}
	}
}


int inv(int x){
	int ret = x,tmp = 1,p = mod - 2;
	while(p > 1){
		if(p & 1) tmp = (tmp * 1LL * ret)%mod;
		ret = (ret * 1LL * ret)%mod;
		p >>= 1;
	}
	ret = (ret * 1LL * tmp)%mod;
	return ret;
}

int main(){
	scanf("%d",&n);
	loop(i,n) {
		scanf("%d",&A[i]);
		lg[i] = log(A[i])/log(10);
	}
	init();
	scanf("%d",&m);
	loop(i,m){
		int pos,val,type;
		scanf("%d %d",&type,&pos);
		if(type == 2) {
			int value = (TOT[pos]*1LL*A[0])%mod;
			double l = q[pos] + lg[0];
			int ans =  pow(10.0,l - (int(l))) + 1e-9;
			while(ans > 9) ans /= 10; 
			printf("%d %d\n",ans,value);
		}
		else {
			--pos;			
			double l = lg[pos];
			int v = inv(A[pos]);
			scanf("%d",&A[pos]);
			lg[pos] = log(A[pos])/log(10);
			for(int r : PathsIBelongTo[pos]) {
				TOT[r] = ((TOT[r] * 1LL * v)%mod * A[pos])%mod;
				q[r] += lg[pos] - l;	
			}
		}
	}		
	return 0;
}
