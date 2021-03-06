#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define all(A) A.begin(),A.END()
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
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << ENDl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << ENDl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

const int MAX = 5000;

char P[MAX][30];
char T[MAX << 2];
int Trie[MAX*30][128];
int fail[MAX*30];
vi END[MAX*30];
int n,m,TT,ctr,K;

void clear(){
	fill(Trie[0],Trie[MAX*30],-1);
	fill(fail,fail + MAX*30,-1);
	loop(i,MAX*30) END[i].clear();
	ctr = 0;
}

void insert(int i){
	int cur = 0;	
	for(char *s = P[i];*s;s++){
		if(Trie[cur][*s] == -1) Trie[cur][*s] = ++ctr;
		cur = Trie[cur][*s];
	}
	cerr << cur << endl;
	END[cur].pb(i);
}

void build_fail(){
	queue<int> q;
	loop(i,128) {
		if(Trie[0][i] != -1) q.push(Trie[0][i]),fail[Trie[0][i]] = 0;
		else Trie[0][i] = 0;
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		loop(i,128){
			if(Trie[u][i] != -1){
				int v = fail[u];
				while(Trie[v][i] == -1) v = fail[v];
				fail[Trie[u][i]] = (Trie[v][i] == -1) ? 0 : Trie[v][i];
				q.push(Trie[u][i]);
				fprintf(stderr,"fail[%d|%c] -> %d\n",Trie[u][i],i,v);
			}
		}
	}
}

int main(){
	scanf("%d",&TT);
	while(TT--){
		clear();
		scanf("%d %d",&m,&K);
		scanf("%s",T); n = strlen(T);
		loop(i,m){
			scanf("%s",P[i]);
			insert(i);
		}
		build_fail();
	}
	return 0;
}
