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

const int MAX = 1e5 + 1e3;
int A[MAX],n;
int GR_EQ[MAX];
int LESS_EQ[MAX];


void init(){
	GR_EQ[n - 1] = LESS_EQ[n - 1] = n - 1;
	for(int i = n - 2;i >= 0;i--){
		if(A[i] < A[i + 1]) GR_EQ[i] = GR_EQ[i + 1],LESS_EQ[i] = i;
		else if(A[i] > A[i + 1]) LESS_EQ[i] = LESS_EQ[i + 1],GR_EQ[i] = i;
		else GR_EQ[i] = GR_EQ[i + 1],LESS_EQ[i] = LESS_EQ[i + 1];
	}
}

int main(){
	int m,a,b;
	scanf("%d %d",&n,&m);
	loop(i,n) scanf("%d",A + i);
	init();
	while(m--){
		scanf("%d %d",&a,&b); a--,b--;
		int v = GR_EQ[a]; v = LESS_EQ[v];
		puts((b <= v) ? "Yes" : "No");
	}
	return 0;
}
