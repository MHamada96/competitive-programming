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

char G[1000][1100],out[1000][1100];
int size[1 << 20],key[1000][1000];
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};
int m,n;


void bfs(int s,int e,int & idx){
	key[s][e] = ++idx;
	size[idx] = 1;
	queue<pi> q; q.push(mp(s,e));
	while(!q.empty()){
		int x = q.front().xx,y = q.front().yy; q.pop();
		loop(i,4){
			int nx = x + dx[i],ny = y + dy[i]; 
			if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
			if(key[nx][ny] || G[nx][ny] != '.') continue;
			key[nx][ny] = idx;
			size[idx]++;
			q.push(mp(nx,ny));
		}
	}
}

int main(){
	int idx = 0;
	scanf("%d %d",&m,&n);
	loop(i,m) scanf("%s",G[i]),strcpy(out[i],G[i]);
	loop(i,m) loop(j,n) if(G[i][j] == '.' && !key[i][j]) bfs(i,j,idx);
	loop(i,m) {
		loop(j,n) if(G[i][j] == '*') {
			int tot = 1;
			vi V;
			loop(k,4){
				int nx = i + dx[k],ny = j + dy[k]; 
				if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
				V.pb(key[nx][ny]);
			}
			sort(all(V));
			V.resize(unique(all(V)) - V.begin());
			for(auto v : V) tot += size[v];
			tot %= 10;
			out[i][j] = tot + '0';
		}
		printf("%s\n",out[i]);
	}
	
	return 0;
}
