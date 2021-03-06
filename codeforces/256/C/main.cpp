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

const int MAX = 5*(1 << 10);

int A[MAX],n;
int ST[MAX][15];
int lg[MAX];
unordered_map<int,vi> M;

void init(){
	lg[0] = -1;
	loop(i,MAX - 1){
		int j = i + 1;
		lg[j] = lg[i] + (LSOne(j) == j);
	}
	
	loop(i,n) ST[i][0] = A[i];
	loop(k,14) loop(i,n){
		ST[i][k + 1] = ST[i][k];
		int o = i + (1 << k);
		if(o < n) ST[i][k + 1] = min(ST[i][k],ST[o][k]);
	}
	
}

int get_min(int s,int e){
	int l = lg[e - s + 1];
	return min(ST[s][l],ST[e - (1 << l) + 1][l]);
}

int solve(int s,int e,int h = 0){
	if(e < s) return 0;
	if(s == e) return 1;
	int H = get_min(s,e),ret = 0,nh;	
	vi & V = M[H];
	nh = H,ret = H - h;
	int u = lower_bound(all(V),s) - V.begin(),v = upper_bound(all(V),e) - V.begin();
	ret += solve(s,V[u] - 1,nh) + solve(V[v - 1] + 1,e,nh);
	for(;u < v - 1;u++) {
		ret += solve(V[u] + 1,V[u + 1] - 1,nh); 	
//		fprintf(stderr,"from (%d,%d) go to (%d,%d)\n",s,e,V[u] + 1,V[u + 1] - 1); 
	}
	return min(ret,e - s + 1);
}

int main(){
	scanf("%d",&n);
	loop(i,n) {
		scanf("%d",A + i);
		if(M.find(A[i]) == M.end()) M[A[i]] = vi();
		M[A[i]].pb(i);
	}
	init();
	int ans = solve(0,n - 1);
	cerr << ans << endl;
	cout << ans << endl;	
	return 0;
}
