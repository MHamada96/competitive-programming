#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define print(A,t) cout << #A << ": "; copy(all(A),ostream_iterator<t>(cout," " )); cout << endl
#define pi pair<int,int>
#define point pi
#define vi vector<int>
#define ll long long
#define pl pair<ll,ll>
#define pre() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define prp(p) cout << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cout << #A << ": "; copy(A,A + n,ostream_iterator<t>(cout," " )); cout << endl
using namespace std;

const int MAX = 1 << 20;
int prev[MAX << 1][21][2],offset = 1 << 20;
int best[MAX << 1][21][2];

int main(){
	loop(i,MAX << 1) loop(j,21) loop(k,2) best[i][j][k] = 1 << 29;	
	int x,y;
	scanf("%d",&x);
	y = x + offset;
	queue<pair<int,pi> > q;
	q.push(mp(y,mp(0,0)));
	best[y][0][0] = 0;
	while(!q.empty()){
		int u = q.front().xx,step = q.front().yy.xx,dir = q.front().yy.yy; q.pop();
	//	if(u == x + offset) {
			cerr << u << " " << step << " " << dir << endl;
	//		break;
	//	}		
		int v = offset - (u - offset);
		if(v >= 0 && v < (MAX << 1)){
			if(best[v][0][!dir] > best[u][step][dir] + 1){
				best[v][0][!dir] = best[u][step][dir] + 1;
				q.push(mp(v,mp(0,!dir)));
			} 
		}
		if(dir) v = u + step;
		else v = u - step;
		step++;
		if(v >= 0 && v < (MAX << 1) && step <= 20){
			if(best[v][step][dir] > best[u][step - 1][dir] + 1){
				best[v][step][dir] = best[u][step - 1][dir] + 1;
				q.push(mp(v,mp(step,dir)));
			} 
		}
	}
	return 0;
}
