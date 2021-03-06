#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
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

int A[1 << 20],n,B[1 << 20],m;
map<int,int> D;

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	if(n == 1){
		puts("-1");
		return 0;
	}
	sort(A,A + n);
	loop(i,n - 1){
		int d = A[i + 1] - A[i];
		if(D.find(d) == D.end()) D[d] = 0;
		D[d]++;
	}
	if(sz(D) > 2){
		puts("0");
		return 0;
	}
	if(sz(D) == 1){
		int d = D.begin()->xx;	
		if(d == 0) printf("1\n%d\n",A[0]);
		else if(n == 2 && d%2 == 0) printf("3\n%d %d %d\n", A[0] - d,A[0] + d/2,A[n - 1] + d); 
		else printf("2\n%d %d\n",A[0] - d,A[n - 1] + d);
		return 0;
	}	
	auto p = D.begin();
	int d1 = p->xx,cnt1 = p->yy;
	p++;
	int d2 = p->xx,cnt2 = p->yy;
	if(cnt2 != 1){
		puts("0");
		return 0;
	}
	if(d2 == 2*d1){
		loop(i,n - 1) if(A[i + 1] - A[i] == d2) printf("1\n%d\n",A[i] + d1);	
	}
	else puts("0");
	return 0;
}
