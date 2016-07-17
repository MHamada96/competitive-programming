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

int n,A[1 << 20];
int e,T;


bool is_prime(int n){
	for(int i = 2;i*i <= n;i++){
			if(n%i == 0) return 0;
	}
	return n > 1;
}
int main(){
	freopen("albert.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		vi V;
		scanf("%d",&n); e = 0;
		loop(i,n){
			scanf("%d",A + e);
			if(!is_prime(A[e])) e++;
		}
		n = e; e = 0;
		loop(i,n){
			if(V.empty() || V.back() <= A[i]) V.pb(A[i]);
			else *upper_bound(all(V),A[i]) = A[i];
		}
		printf("%lu\n",sz(V));
	}
	return 0;
}
