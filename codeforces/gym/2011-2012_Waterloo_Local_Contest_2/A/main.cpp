#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,_ = (n);i < _;i++)
#define range(i,a,b) for(int i = (a),_ = (b);i <= _;i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b),_ = (a);i >= _;i--)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
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

const int MAX = 1 << 20;
int id[MAX],W[MAX];

int get(int a){
	return id[a] = (a == id[a]) ? a : get(id[a]);
}

int join(int a,int b){
	a = get(a),b = get(b);
	if(a == b) return W[a];
	if(W[a] < W[b]) swap(a,b);
	W[a] += W[b];
	id[b] = a;
	return W[a];
}

int main(){
	int T,n;
	scanf("%d",&T);
	string u,v;
	while(T--){
		scanf("%d",&n);
		int ctr = 0;
		map<string,int> M;
		while(n--){
			cin >> u >> v;
			if(M.find(u) == M.end()) id[ctr] = ctr,W[ctr] = 1,M[u] = ctr++;
			if(M.find(v) == M.end()) id[ctr] = ctr,W[ctr] = 1,M[v] = ctr++;
			printf("%d\n",join(M[u],M[v]));
		}
	}
	return 0;
}