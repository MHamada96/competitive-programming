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

const int MAXN  = 500000;

int head[MAXN],nxt[MAXN << 1],to[MAXN << 1],edgeCnt,n;
char line[MAXN + 10];
int inTime[MAXN],outTime[MAXN],dfs_time;
vi nodesInLevel[MAXN];
vector<vi> charCnt[MAXN];

void add_edge(int a,int b){
	to[edgeCnt] = b;
	nxt[edgeCnt] = head[a];
	head[a] = edgeCnt++;
}

void addBiEdge(int a,int b){
	add_edge(a,b);
	add_edge(b,a);
}

void dfs(int u,int p = -1,int depth = 0){
	cerr << u << " " << p << endl;
	inTime[u] = dfs_time++;
	cerr << "a" << endl;
	nodesInLevel[depth].pb(u);
	cerr << "b" << endl;
	charCnt[depth].pb(vi(26,0));
	cerr << "c" << endl;
	cerr << line[u] << endl;
	charCnt[depth].back()[line[u]-'a']++;
	cerr << "here" << endl;
	for(int e = head[u]; ~e ; e = nxt[e]) if(to[e] != p) dfs(to[e],u,depth + 1);
	outTime[u] = dfs_time - 1;	
}

void init(){
	fill(head,head + n,-1);
}

void postprocess(){
	loop(level,MAXN){
		for(int i = 1;i < (int)sz(charCnt[level]);i++)
			loop(j,26) charCnt[level][i][j] += charCnt[level][i - 1][j];
	}
}	

bool cmp(const int & a,const int & b){
	return inTime[a] < b;
}

int main(){
	init();
	int m;
	scanf("%d %d",&n,&m);
	loop(i,n - 1){
		int a;
		scanf("%d",&a);
		addBiEdge(a - 1,i + 1);	
	}
	scanf("%s",line);
	dfs(0);
	//postprocess();
	/*while(m--){
		int a,b;
		scanf("%d %d",&a,&b); b--; a--;
		auto u = lower_bound(all(nodesInLevel[b]),inTime[a],&cmp) - nodesInLevel[b].begin();
		auto v = upper_bound(all(nodesInLevel[b]),outTime[a],&cmp) - nodesInLevel[b].begin();
	}*/
	return 0;
}
