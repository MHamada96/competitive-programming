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

int n,k,d;
int A[1000][1000];
int p;

bool gen(int l){
	if(l == d) return ++p == n;
	range(i,1,k){
		A[p][l] = i;
		if(gen(l + 1)) return 1;
		copy(A[p - 1],A[p - 1] + l,A[p]);
	}
	return 0;
}

int main(){
	cin >> n >> k >> d;
	if(gen(0)){
		loop(j,d) loop(i,n)  printf("%d%c",A[i][j]," \n"[i == n - 1]);
	}
	else puts("-1");
	return 0;
}
