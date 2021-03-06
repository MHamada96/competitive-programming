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

const int MAX = 3e5;
pair<ll,char> S[MAX],T[MAX],X[MAX + MAX];
int n,m;
int Z[MAX + MAX];

void buildZ(pair<ll,char> *S,int *Z,int LEN){
	int L = 0, R = 0;
	for (int i = 1; i < LEN; i++) {
		if (i > R) {
			L = R = i;
			while (R < LEN && X[R-L] == X[R]) R++;
    			Z[i] = R-L; R--;
  		} else {
    			int k = i-L;
    			if (Z[k] < R-i+1) Z[i] = Z[k];
    			else {
      				L = i;
      				while (R < LEN && X[R-L] == X[R]) R++;
      				Z[i] = R-L; R--;
    			}
  		}
	}

}


vector<pair<ll,char> > V;

int main(){
	char s[3];
	int N,M; n = m = 0;
	scanf("%d %d",&M,&N);
	loop(i,M) {
		scanf("%I64d-%s",&S[i].xx,s);
		S[i].yy = s[0];
		if(!V.empty() && V.back().yy == S[i].yy) V.back().xx += S[i].xx;
		else V.pb(S[i]);
	}
	m = sz(V);
	loop(i,m) S[i] = V[i];
	V.clear();
	loop(i,N) {
		scanf("%I64d-%s",&T[i].xx,s);
		T[i].yy = s[0];
		if(!V.empty() && V.back().yy == T[i].yy) V.back().xx += T[i].xx;
		else V.pb(T[i]);
	}
	n = sz(V);
	loop(i,n) T[i] = V[i];
	
	if(n == 1){
		ll ans = 0;
		loop(i,m){
			if(S[i].yy == T[0].yy && S[i].xx >= T[0].xx) ans += max(0LL,S[i].xx - T[0].xx + 1);
		}
		cout << ans << endl;
	}
	else if(n == 2){
		int ans = 0;
		loop(i,m - 1) 
		if(S[i].yy == T[0].yy && S[i + 1].yy == T[1].yy && S[i].xx >= T[0].xx && S[i + 1].xx >= T[1].xx){
			ans++;
		}
		cout << ans << endl;
	}
	else{
		int L = n + m - 1,ans = 0;
		loop(i,n - 2) X[i] = T[i + 1];
		X[n - 2].xx = 0,X[n - 2].yy = 0;
		loop(i,m) X[i + n - 1] = S[i];
		buildZ(X,Z,L);
		loop(j,m){
			int i = j + n - 1;
			if(Z[i] == n - 2){
				if(X[i - 1].yy == T[0].yy && X[i - 1].xx >= T[0].xx && X[i + n - 2].yy == T[n - 1].yy && X[i + n - 2].xx >= T[n - 1].xx){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
