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

int A[2000],B[2000],n,m;
ll Sa = 0,Sb = 0;
int Z[2000][4][2];


int main(){
	scanf("%d %d",&n);
	loop(i,n) scanf("%d",A + i),Sa += A[i];
	scanf("%d %d",&m);
	loop(i,m) scanf("%d",B + i),Sb += B[i];
	loop(i,n) {
		Z[i][2][1] = Z[i][3][1] = INT_MAX;
		loop(j,m){
			ll d = abs(A[i] * 1LL - B[j]);
			if(Z[i][1][1] < d){
				
			}
		}
	}
	
	return 0;
}
