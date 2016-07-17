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

char G[2][2000]; 
int n;
queue<pi> q;

int f(int & ret){
	ret = 0; bool c = 0;
	loop(i,2) loop(j,n)
	if(G[i][j] == '.'){
		int k = j;
		while(k < n && G[i][k] != 'X') k++;
		if(k - j == 1) q.push(mp(i,j)),c = 1;
		ret ++;
		j = k - 1;
	}
	return c;
}

int g(){
	int ret = 0;
	while(!q.empty()){
		int i = q.front().xx,j = q.front().yy; q.pop();
		if(G[i][j] == 'o') continue;
		if(G[!i][j] != '.') continue;
		ret++;
		G[i][j] = 'o';
		for(int k = j + 1;k < n;k++) {
			if(G[!i][k] == 'X') break;		
			G[!i][k] = 'o';
		}
		for(int k = j; k >= 0;k--) {
			if(G[!i][k] == 'X') break;		
			G[!i][k] = 'o';
		}
	}
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	loop(t,T){
		scanf("%d %s %s",&n,G[0],G[1]);
		int ans = 0,x;
		f(x); 
		ans = g();
		f(x);
		while(!q.empty()) q.pop();
		ans += x;
		printf("Case #%d: %d\n",t + 1,ans);
	}	
	return 0;
}
