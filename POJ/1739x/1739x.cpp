#include <cstdio>
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

#define is_visited(i,j) (V[i] & (1 << j))

short m,n,V[10],degree[10],dx[] = {-1,1,0,0},dy [] = {0,0,-1,1};

inline void mark(short x,short y){
	
}

int bt(short x,short y,short ctr){
	if(ctr == 1) return x == m - 1 && y == n - 1;
	if(x == m - 1 && y == n - 1) return 0;
	if(is_deadend(x,y)) return 0;
	int ret = 0;
	mark(x,y);
	
	unmark(x,y);
}

int main(){
	char G[10][10]; short ctr;
	while(scanf("%hd %hd",&m,&n) == 2 && m && n){ 
		ctr = 0;
		loop(i,m) V[i] = degree[i] = 0;
		loop(i,m){
			scanf("%s",G[i]);
			loop(j,n) {
				if(G[i][j] == '#') V[i] |= 1 << j;
				ctr += !is_visited(i,j);			
			}
		}
		loop(i,m) loop(j,n){
			short xctr = 0;
			loop(k,4){
				short ni = i + dx[k],nj = j + dy[k];
				if(ni == -1 || ni == m || nj == -1 || nj == n) continue;
				xctr += !is_visited(ni,nj);
			}
			degree[i] |= (7 & xctr) << (i * 3);
		}
		printf("%d\n",bt(m,1,ctr));
	}
	return 0;
}