#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
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
int n,m;
int W[MAX],id[MAX];
int head[MAX],from[MAX << 1],nxt[MAX << 1],to[MAX << 1],C[MAX << 1],idx = 0;
ll cost[MAX];
pair<int,pi> E[MAX];
char out[MAX << 1];

void addEdge(int a,int b,int c){
	from[idx] = a;
	to[idx] = b;
	C[idx] = c;
	nxt[idx] = head[a];
	head[a] = idx++;
}

void addBiEdge(int a,int b,int c){
	addEdge(a,b,c);
	addEdge(b,a,c);
}

int get(int a){
	return id[a] = (a == id[a]) ? a : get(id[a]);
}

bool connected(int a,int b) {return get(a) == get(b);}

void join(int a,int b){
	a = get(a),b = get(b);
	if(W[a] < W[b]) swap(a,b);
	W[a] += W[b];
	id[b] = a;
}

ll dfs(int u,int p){
	ll ctr = 1;
	for(int e = head[u];e != -1;e = nxt[e]){
		if(to[e] == p) continue;
		ll tmp = dfs(to[e],u);
		cost[e & (~1)] = tmp*(n - tmp);
		ctr += tmp;
	}
	return ctr;
}

int main(){
	scanf("%d %d",&n,&m);
	loop(i,n + 1) id[i] = i,W[i] = 1,head[i] = -1;	
	loop(i,m) scanf("%d %d %d",&E[i].yy.xx,&E[i].yy.yy,&E[i].xx);
	sort(E,E + m);
	loop(i,m){
		if(connected(E[i].yy.xx,E[i].yy.yy)) continue;
		join(E[i].yy.xx,E[i].yy.yy);
		addBiEdge(E[i].yy.xx,E[i].yy.yy,E[i].xx);
	}
	dfs(1,0);
	set<int> S;	
	for(int i = 0;i < idx;i += 2) {
		int position = C[i];
		for(;cost[i];cost[i] >>= 1,position++){
			if(cost[i] & 1){
				int tmp = position;
				while(S.find(tmp) != S.end()){
					S.erase(tmp);
					tmp++;
				}
				S.insert(tmp);
			}
		}
	}
	int position = 0;
	auto p = S.begin();
	auto v = S.end(); --v;
	int mx = *v;
	for(;p != S.end();position++){
		out[mx - position] = (position == *p) ? '1' : '0';
		if(position == *p) p++;
	}
	puts(out);
	return 0;
}