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

const int MAX = 1 << 20;
char line[MAX];
int Z[MAX],n;
int cnt[MAX];

void buildZ(char *P,int L,int *Z){
	int l = 0,r = 0;
	Z[0] = L;	
	range(i,1,n - 1){
		if(i > r){
			l = r = i;
			while(r < L && P[r - l] == P[r]) r++;
			Z[i] = r - l; 
			r--;
		}
		else{
			int k = i - l;
			if(Z[k] < r - i + 1) Z[i] = Z[k];
			else{
				l = i;
				while(r < L && P[r - l] == P[r]) r++;
				Z[i] = r - l;
				r--;
			}
		}
	}
}

int main(){
	scanf("%s",line);
	n = strlen(line);
	buildZ(line,n,Z);
	vi cand;	
	loop(i,n){
		if(i + Z[i] == n)
			cand.pb(Z[i]);
		cnt[Z[i]]++;
	}
	sort(Z,Z + n);
	sort(all(cand));
	rrep(i,n - 1) cnt[i] += cnt[i + 1];
	
	printf("%lu\n",sz(cand));
	//cerr << sz(sol) << endl;
	for(auto p : cand) {
		printf("%d %d\n",p,cnt[p]);
	//	prp(p);
	}		
	return 0;
}
