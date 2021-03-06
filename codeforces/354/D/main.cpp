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

int D[1000][1000][4];
char G[1000][1010];
int doors[10001][1010][4];
int X1,X2,Y1,Y2;
int dx [] = {0,1,0,-1},dy [] = {1,0,-1,0};
int m,n;

void rotate(int *A){
	int B[4];
	loop(i,4) B[(i + 1)%4] = A[i];
	copy(B,B + 4,A);
}

bool can(int x1,int y1,int x2,int y2,int r,int o){
	int A[4],B[4];
	copy(doors[x1][y1],doors[x1][y1] + 4,A);
	copy(doors[x2][y2],doors[x2][y2] + 4,B);
	loop(i,r) rotate(A),rotate(B);
	return A[o] && B[(o + 2)%4];
}

void parse(int x,int y){
	if(G[x][y] == '+') loop(i,4) doors[x][y][i] = 1;
	else if(G[x][y] == '-') doors[x][y][0] = doors[x][y][2] = 1;
	else if(G[x][y] == '|') doors[x][y][1] = doors[x][y][3] = 1;
	else if(G[x][y] == '^') doors[x][y][3] = 1;
	else if(G[x][y] == 'v') doors[x][y][1] = 1;
	else if(G[x][y] == '>') doors[x][y][0] = 1;
	else if(G[x][y] == '<') doors[x][y][2] = 1;
	else if(G[x][y] != '*') {
		loop(i,4) doors[x][y][i] = 1;
		if(G[x][y] == 'L') doors[x][y][2] = 0;
		else if(G[x][y] == 'R') doors[x][y][0] = 0;
		else if(G[x][y] == 'U') doors[x][y][3] = 0;
		else doors[x][y][1] = 0;
	}
}

int bfs(){
	queue<pair<pi,int> > q;
	q.push(mp(mp(X1,Y1),0)); D[X1][Y1][0] = 1;
	while(!q.empty()){
		int x = q.front().xx.xx,y = q.front().xx.yy,r = q.front().yy; q.pop();
		if(x == X2 && y == Y2) return D[X2][Y2][r] - 1;
		loop(i,4){
			int nx = x + dx[i],ny = y + dy[i];
			if(nx < 0 || nx >= m || ny < 0 || ny >= n || D[nx][ny][r]) continue;
			if(!can(x,y,nx,ny,r,i)) continue;
			D[nx][ny][r] = D[x][y][r] + 1; 
			q.push(mp(mp(nx,ny),r));
		}
		int nr = r;
		nr ++; nr = (nr == 4) ? 0 : nr;
		if(!D[x][y][nr]){
			D[x][y][nr] = D[x][y][r] + 1;
			q.push(mp(mp(x,y),nr));
		}
	}
	return - 1;
}

int main(){
	scanf("%d %d",&m,&n);
	loop(i,m){
		scanf("%s",G[i]);
		loop(j,n) parse(i,j);
	}
	scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
	X1--,Y1--;
	X2--,Y2--;
	cout << bfs() << endl;
	return 0;
}
