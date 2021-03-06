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

char A[1 << 20],B[1 << 20];

int main(){
	int T,n,ans,ctr;
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",A,B); n = strlen(A); ctr = ans = 0;
		vi ones,zeros;
		loop(i,n){
			ctr += A[i] == '1';
			if(A[i] == B[i]) continue;
			if(A[i] == '1') {
				if(zeros.empty()) ones.pb(i);
				else zeros.pop_back(),ans ++;
			}
			else{
				if(ones.empty()) zeros.pb(i);
				else ones.pop_back(),ans++;
			}
		}
		if(zeros.empty() && ones.empty()) {
			printf("Lucky Chef\n%d\n",ans);
		}
		else if(zeros.empty()){
			if(ctr == n) puts("Unlucky Chef");
			else printf("Lucky Chef\n%d\n",ans + (int)sz(ones));
		}
		else{
			if(ctr == 0) puts("Unlucky Chef");
			else printf("Lucky Chef\n%d\n",ans + (int)sz(zeros));			
		}
	}
	return 0;
}
