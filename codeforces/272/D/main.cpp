#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
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
 
const int MAX = 1e5 + 1e2;
int n,m;
int A[MAX << 1],ord[MAX << 1],F[MAX << 1],p2[MAX << 1];

int mul(int x,int y){
	x %= m;
	y %= m;
	return (x * 1LL * y)%m;
}

int POW(int x,int p){
	if(!p) return mul(1,1);
	int y = mul(1,1); x = mul(x,1);
	for(;p > 1;p >>= 1){
		if(p & 1) y = mul(x,y);
		x = mul(x,x);
	}
	return mul(x,y);
}


int f(int s,int e){
	int ctr = p2[e - s + 1];
	for(;s < e;s++){
		if(ord[s]/2 == ord[s + 1]/2) ctr--;
	}
	assert(ctr >= 0);
	return mul(F[e - s + 1],POW(2,ctr));
}

void init(){
	F[0] = mul(1,1);
	loop(i,2*n) {
		int j = i + 1;
		p2[i + 1] = p2[i];
		while(j%2 == 0) j >>= 1,p2[i + 1]++;
		F[i + 1] = mul(F[i],j);
	}
}

int main(){
	scanf("%d",&n);	
	loop(i,n) scanf("%d",&A[i << 1]);
	loop(i,n) scanf("%d",&A[(i << 1) | 1]);
	loop(i,2*n) ord[i] = i;
	scanf("%d",&m);
	
	sort(ord,ord + 2*n,[](const int & a,const int & b){
		return tie(A[a],a) < tie(A[b],b); 
	});
	
	init();	
	
	int ans = mul(1,1);
	loop(i,2*n){
		int j = i;
		while(j < 2*n && A[ord[i]] == A[ord[j]]) j++;
		ans = mul(ans,f(i,j-1));
		i = j - 1;
	}
	cout << ans << endl;
	return 0;
}
