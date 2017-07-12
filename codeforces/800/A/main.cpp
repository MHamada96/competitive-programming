#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
#define ll long long
#define pi pair<int,int>
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define what_is(x) cerr << #x << " is " << x << endl
#define bit_lg(x) (assert(x > 0),__builtin_ffsll(x) - 1)
const double PI = acos(-1);
using namespace std;

const int MAX = 100*1000 + 10;
const double EPS = 1e-9;

int A[MAX],B[MAX],n,p;


bool can(double t){
	double r = 0;
	loop(i,n){
		r += max(0.0,A[i]*t - B[i])/p;
		if(r > t) return 0;
	}
	return 1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	scanf("%d %d",&n,&p);

	loop(i,n) scanf("%d %d",A + i,B + i);
	double s = 0,e = 1e18;
	for(int k = 0;k < 10000 && e - s > EPS;k++){
		double m = s + (e - s)/2;
		if(can(m)) s = m + EPS;
		else e = m - EPS;
	}
	if(s > 9e17) puts("-1");
	else printf("%.9f\n",s);
	return 0;
}
