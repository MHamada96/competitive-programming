/*
TASK: prime3
LANG: C++
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
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

const int MAX = 100000;
int not_prime[MAX],M,N;
vi cand[161051];
int colsum[5],rowsum[5];
vector<vi> sol;

int mx = 0;
inline void process(int p){
	char s[10]; sprintf(s,"%d",p);
	loop(mask,1 << 5){
		int v = 0;		
		loop(i,5){		
			v *= 11;
			if(mask & (1 << i)) v += 10;
			else v += s[i] - '0'; 
		}
		cand[v].pb(p);
	}
}

void sieve(){
	not_prime[0] = not_prime[1] = 1;
	for(ll i = 2;i < MAX;i++){
		if(not_prime[i] == 0){
			if(i > 10000) process(i);
			for(ll j = i*i;j < MAX;j += i)
				not_prime[j] = 1;
		}
	}
}

int G[6][6];
vector<vi> OUT;

inline bool check1(int x,int y,int dx,int dy,int *A){
	int nx = x,ny = y;
	loop(i,5){
		if(G[nx][ny] != 10 && A[i] != G[nx][ny]) return 0;
		if(G[nx][ny] == 10 && colsum[ny] + A[i] > M) return 0;
		if(G[nx][ny] == 10 && rowsum[nx] + A[i] > M) return 0;
		nx += dx;
		ny += dy;	
	}
	return 1;
}
inline void put(int x,int y,int dx,int dy,int *A,int *B){
	int nx = x,ny = y;
	loop(i,5){
		if(G[nx][ny] == 10 && A[i] != 10) colsum[ny] += A[i],rowsum[nx] += A[i];
		if(G[nx][ny] != 10 && A[i] == 10) colsum[ny] -= G[nx][ny],rowsum[nx] -= G[nx][ny];
		B[i] = G[nx][ny];
		G[nx][ny] = A[i];
		nx += dx;
		ny += dy;
	}
}

inline int get(int x,int y,int dx,int dy){
	int v = 0;
	loop(i,5){
		v = v * 11 + G[x][y];
		x += dx;
		y += dy;
	}
	return v;
}

inline void convert(int p,int *A,int & s){
	int i = 4; s = 0;
	while(i >= 0){
		A[i] = p%10;
		s += A[i];
		p /= 10;
		i--;
	}
}

inline void row(int i,int & x,int & y,int & dx,int & dy){
	x = i;
	y = 0;
	dx = 0;
	dy = 1;
}

inline void col(int i,int & x,int & y,int & dx,int & dy){
	x = 0;
	y = i;
	dx = 1;
	dy = 0;
}

void get_dir(int i,int & x,int & y,int & dx,int & dy){
	if(i == 0) x = 0,y = 0,dx = 1,dy = 1;
	else if(i == 1) x = 4,y = 0,dx = -1,dy = 1;
	else if(i == 2) col(1,x,y,dx,dy);
	else if(i == 3) col(3,x,y,dx,dy);
	else if(i == 4) row(2,x,y,dx,dy);
	else if(i == 5) col(0,x,y,dx,dy);
	else if(i == 6) col(4,x,y,dx,dy);
	else if(i == 7) row(1,x,y,dx,dy);
	else if(i == 8) row(3,x,y,dx,dy);
	else if(i == 9) col(2,x,y,dx,dy);
	else if(i == 10) row(0,x,y,dx,dy);
	else row(4,x,y,dx,dy);
}

void PRINT(){
	loop(j,5) {
		loop(k,5) printf("%d",G[j][k]);
		puts("");
	}
	puts("");
}

bool check2(){
	loop(i,5) if(G[0][i] == 0) return 0;
	loop(col,5){
		int v1 = 0,v2 = 0;
		loop(row,5){
			v1 = v1 * 10 + G[row][col];
			v2 += G[row][col];		
		}
		if(not_prime[v1] || v2 != M) return 0;
	}
	return 1;
}

void bt(int i){
	if(i == 12){
		//if(!check2()) return;		
		vi ans(5,0);
		loop(j,5) loop(k,5) ans[j] = ans[j] * 10 + G[j][k];
		sol.pb(ans);		
		return;
	}
	int v = 0,x,y,dx,dy,A[5],B[5];
	get_dir(i,x,y,dx,dy);
	v = get(x,y,dx,dy);
	loop(k,sz(cand[v])){
		int p = cand[v][k],s;
		convert(p,A,s);
		if(s != M) continue;
		if(!check1(x,y,dx,dy,A)) continue;
		put(x,y,dx,dy,A,B);
		bt(i + 1);
		put(x,y,dx,dy,B,A);
	}
}

int main(){
	//freopen("prime3.in","r",stdin);
	//freopen("prime3.out","w",stdout);
	sieve();
	scanf("%d %d",&M,&N);	
	loop(i,5) loop(j,5) G[i][j] = 10;
	G[0][0] = N;
	bt(0);
	sort(all(sol));
	loop(i,sz(sol)){
		loop(j,5) printf("%d\n",sol[i][j]);
		puts("");
	}
	return 0;
}