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

int M,N;
char G[1000][1000];

char get_color(int x,int y){
	char u = 0,v = 0;
	if(x) u = G[x - 1][y];
	if(y) v = G[x][y - 1];
	if(u == 'A') return (v == 'B') + 'B';
	else if(u == 'B') return (v == 'A')*2 + 'A';
	else return 'A' + (v == 'A');
}

char paint(int sx,int ex,int sy,int ey){
	char c = get_color(sx,sy);
	for(int i = sx;i <= ex;i++) for(int j = sy;j <= ey;j++) G[i][j] = c;
	return c;
}

char solve(int x,int y){
	if(x == m && y == n) return 0;
	int m = M - x,n = N - y,d = min(m,n);	
	if(get_color(x,y) == 'A') {
		paint(x,x + d - 1,y ,y + d - 1);
		solve(x + d,y + d);
	}
	if(get_color(x,y) == 'B'){
		if(get_color(x,y + 1) == 'A') 
	}
}

int main(){
	scanf("%d %d",&M,&N);
	solve(0,0);
	loop(i,M) puts(G[i]);
	return 0;
}
