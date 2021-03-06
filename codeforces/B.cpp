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

int A[1 << 10],B[1 << 10],n;

bool done(){
	loop(i,n) if(!B[i]) return 0;
	return 1;
}

int solve(){
	int d = 1,v = 0,ctr;
	fill(B,B + n,0);	
	for(ctr = 0;ctr < n + 3 && !done();++ctr){
		for(int i = (d == 1) ? 0 : (n - 1); i >= 0 && i < n; i += d) 
			if(!B[i] && A[i] <= v) 
				++v,B[i] = 1;
		d = (d == 1) ? -1 : 1;  
	}
	return done() ? ctr - 1 : INT_MAX;
}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	printf("%d\n",solve());
	return 0;
}
