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

int n;
int A[1 << 20];
ll S[1 << 20];
ll f(int i,int l){
	ll s = S[n - 1] - ((n - l - 1 >= 0) ? S[n - l - 1] : 0) + S[i] - ((i - l - 1 >= 0) ? S[i - l - 1] : 0);
	return s;
}

void choose(int i,ll l1,int & j,int & l2,ll & s2){
	ll s1 = f(i,(l1 - 1)/2);
	if(s1*l2 - A[i]*(l1*l2) > s2*l1 - A[j]*(l1*l2)){
		s2 = s1;
		j = i;
		l2 = l1;
	}
}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",&A[i]);
	sort(A,A + n);
	loop(i,n){
		S[i] = A[i];
		if(i) S[i] += S[i - 1];
	}
	ll ans = 0; int p = 0,l = 1;
	loop(i,n){
		int s = 0,e = min(i,n - i - 1);
		while(e - s > 1){
			int m1 = s + (e - s + 1) / 3,m2 = m1 + (e - s + 1)/3;
			if((2*m2 + 1)*f(i,m1) < (2*m1 + 1)*f(i,m2)) s = m1 + 1;
			else e = m2 - 1;
		}
		choose(i,2*s + 1,p,l,ans);
		choose(i,2*e + 1,p,l,ans);
	}	
	printf("%d\n",l);
	for(int i = p,L = (l - 1)/2 + 1;L > 0;L --,i--){
		printf("%d ",A[i]);
	} 	
	for(int i = n - 1,L = (l - 1)/2;L > 0;L--,i--){
		printf("%d ",A[i]);
	}
	return 0;
}
