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

int A[1 << 20];
vector<pi> bucket[1 << 10];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int bucket_size = sqrt(n) + 5; bucket_size = min(bucket_size,n);
	loop(i,n){
		scanf("%d",A + i);
		bucket[i/bucket_size].pb(mp(A[i],i + 1));
	}
	loop(i,(n - 1)/bucket_size + 1) sort(all(bucket[i]));
	while(m--){
		int l,r,a;
		scanf("%d %d %d",&l,&r,&a); l--,r--;
		int u = l/bucket_size,v = r/bucket_size;
		if(u == v){
			bool c = 0;
			range(i,l,r) {
				if(A[i] != a){
					printf("%d\n",i + 1);
					c = 1;
					break;
				}
			}
			if(!c) puts("-1");
		}
		else{
			bool c = 0;
			range(i,l,bucket_size*(u + 1) - 1){
				if(A[i] != a){
					printf("%d\n",i + 1);
					c = 1;
					break;
				}
			}
			if(c) continue;
			range(i,bucket_size*v,r){
				if(A[i] != a){
					printf("%d\n",i + 1);
					c = 1;
					break;
				}
			}
			if(c) continue;
			for(++u; u < v;u++){
				if(bucket[u][0].xx != a){
					printf("%d\n",bucket[u][0].yy);
					c = 1;
					break;
				}
				if(bucket[u].back().xx != a){
					printf("%d\n",bucket[u].back().yy);
					c = 1;
					break;
				}
			}
			if(!c) puts("-1");
		}
	}
	return 0;
}
