#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define print(A,t) cout << #A << ": "; copy(all(A),ostream_iterator<t>(cout," " )); cout << endl
#define pi pair<int,int>
#define point pi
#define vi vector<int>
#define ll long long
#define pl pair<ll,ll>
#define pre() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)
using namespace std;


int main(){
	int T,n; ll A[3],B[3];
	scanf("%d",&T);
	while(T--){
		loop(i,3) A[i] = 0;
		scanf("%d",&n);
		loop(i,n){
			loop(j,3){
				scanf("%lld",B + j);
				A[j] += B[j];
			}
		}
		loop(i,3) printf("%.4f\n",A[i] * 1.0 / n);
	}
	return 0;
}
