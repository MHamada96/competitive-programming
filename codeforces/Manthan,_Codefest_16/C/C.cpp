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

char line[11001],Z[11001];
int ctr = 0,n,m;
int trie[1200000][26];
int fail[1200000];
int dp[10000],link[10000];
vi   NXT[1200000],nxt[11001];
vector<string> P;

void insert(int i){
	int cur = 0;
	char *z = Z;	
	for(int i = 0,L = strlen(Z);i < L;i++){
		char *z = Z + i;
		if(trie[cur][*z - 'a'] == 0) trie[cur][*z - 'a'] = ++ctr;
		cur = trie[cur][*z - 'a'];
		z++;
	}
	NXT[cur].pb(i);
}


void build_fail(){
	queue<int> q;
	for(char c = 'a';c <= 'z';c++)
		if(trie[0][c - 'a']){
			fail[trie[0][c - 'a']] = 0;
			q.push(trie[0][c - 'a']);
		}
	while(!q.empty()){
		int r = q.front(); q.pop();
		for(char a = 'a';a <= 'z';a++){
			if(trie[r][a - 'a']){
				int u = trie[r][a - 'a'];
				q.push(u);
				int v = fail[u];
				while(v && trie[v][a - 'a'] == 0) v = fail[v];
				fail[u] = trie[v][a];
				for(auto v : NXT[fail[u]]) NXT[u].pb(v);
			}
		}
	}
}

int solve(int p){
	if(p == n) return 2;
	if(dp[p] != 0) return dp[p];
	dp[p] = 1;
	for(auto v : nxt[p])
		if(solve(p + len(P[v])) == 2){
			dp[p] = 2;
			link[p] = v;
			break;
		}
	return dp[p];
}

int main(){
	scanf("%d %s %d",&n,line,&m);
	loop(i,m){
		scanf("%s",Z);
		P.pb(string(Z));
		int L = strlen(Z);
		loop(i,L) Z[i] = tolower(Z[i]);
		reverse(Z,Z + L);
		insert(i);		
	}
	build_fail();
	int cur = 0;
	for(int i = 0;i < n + 1;i++){
		for(auto v : NXT[cur]) {
			nxt[i - len(P[v])].pb(v);
		}
		while(cur && trie[cur][line[i] - 'a'] == 0) cur = fail[cur];
		cur = trie[cur][line[i] - 'a'];
	}
	assert(solve(0) == 2);
	int p = 0;
	while(p < n){
		strcpy(Z,P[link[p]].c_str());
		printf("%s%s",Z,(p + strlen(Z) == n) ? "\n" : " ");
		p += strlen(Z);
	}
	puts("");
}
