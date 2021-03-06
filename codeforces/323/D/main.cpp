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

const int MAX = 100*310;

int A[MAX],n,K,M,diff;

void getLNDS(){
	vi LIS;
	int k = min(K,310);
	loop(j,k){
		int oe = LIS.size();
		loop(i,n){
			if(LIS.empty() || LIS.back() <= A[i]) LIS.pb(A[i]);
			else *upper_bound(all(LIS),A[i]) = A[i];
		}
		diff = LIS.size() - oe;
	}	
	M = LIS.size();
	cerr << M << endl;
}

int main(){
	scanf("%d %d",&n,&K);
	loop(i,n) scanf("%d",A + i);
	getLNDS();
	if(K <= 310 || M == 1) printf("%d\n",M);
	else printf("%lld\n",M + diff*(K - 310LL));
	return 0;
}
