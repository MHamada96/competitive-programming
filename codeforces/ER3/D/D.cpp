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
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define prp(p) cout << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cout << #A << ": "; copy(A,A + n,ostream_iterator<t>(cout," " )); cout << endl
using namespace std;

int n,m,k,S;
pi A[1 << 20],B[1 << 20];
vector<pl> V1,V2;


inline ll f(int x,int p){
	ll c1 = A[p].xx,c2 = B[p].xx;
	if(sz(V1) < x) c1 = 1LL << 60;	
	else if(x) c1 *= V1[x - 1].xx;
	else c1 = 0;
	x = k - x;
	if(sz(V2) < x) c2 = 1LL << 60;	
	else if(x) c2 *= V2[x - 1].xx;
	else c2	 = 0;
	//cerr << p + 1 << " " << k - x << " " <<  c1 + c2 << endl;
	return c1 + c2;
}

int pos(int p){
	if(p == -1) return -1;	
	loop(x,k + 1) {
		if(f(x,p) <= S) 
			return x;
	}
	return -1;
}

int main(){
	scanf("%d %d %d %d",&n,&m,&k,&S);
	loop(i,n) {
		scanf("%d",&A[i].xx);
		A[i].yy = i + 1;
		if(i && A[i - 1] < A[i]) A[i] = A[i - 1];
	}
	loop(i,n) {
		scanf("%d",&B[i].xx);
		B[i].yy = i + 1;
		if(i && B[i - 1] < B[i]) B[i] = B[i - 1];
	}
	loop(i,m){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a == 1) V1.pb(mp(b+0LL,i + 1LL));
		else V2.pb(mp(b+0LL,i+1LL));
	}	  
	sort(all(V1)); loop(i,sz(V1)) V1[i].xx += i ? V1[i - 1].xx : 0;
	sort(all(V2)); loop(i,sz(V2)) V2[i].xx += i ? V2[i - 1].xx : 0;
	int s = 0,e = n - 1;
	while(s < e){
		int m = s + ((e - s) >> 1);
		if(pos(m) == -1) s = m + 1;
		else e = m;
	}
	int p = pos(s);	
	//cerr << s + 1 << " " << p << " " << f(s,p) << endl;
	if(p >= 0) {
		printf("%d\n",s + 1);
		loop(i,p) printf("%d %d\n",(int)V1[i].yy,A[s].yy);
		loop(i,k - p) printf("%d %d\n",(int)V2[i].yy,B[s].yy);
	}
	else cout << -1 << endl;
	return 0;
}
