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

const int MAXN = 1000;

int A[MAXN][MAXN][2];
int dp[MAXN][MAXN],n;
int nxt[MAXN][MAXN][2];
int f(int c){
	dp[0][0] = A[0][0][c];
	loop(i,n) loop(j,n){
		if(i) {
			dp[i][j] = dp[i - 1][j] + A[i][j][c];
			nxt[i][j][c] = 1;
		}
		if(j) {
			dp[i][j] = dp[i][j - 1] + A[i][j][c];
			nxt[i][j][c] = 0;
		}
		if(i && j) {
			dp[i][j] = A[i][j][c];
			if(dp[i][j - 1] < dp[i - 1][j]) {
				dp[i][j] += dp[i][j - 1];
				nxt[i][j][c] = 0;
			}
			else{
				dp[i][j] += dp[i - 1][j];
				nxt[i][j][c] = 1;
			}
		}	
	}
	return dp[n - 1][n - 1];
}

int get_exp(int a,int p){
	int ret = 0;
	while(a%p == 0) ret++,a /= p;
	return ret;
}

char out[2*MAXN];

int main(){
	int ans = INT_MAX,zerox,zeroy;
	scanf("%d",&n);
	loop(i,n) loop(j,n){
		scanf("%d",&A[i][j][0]);
		if(A[i][j][0] == 0) ans = 1,A[i][j][0] = 1,zerox = i,zeroy = j;
		A[i][j][1] = get_exp(A[i][j][0],5);
		A[i][j][0] = get_exp(A[i][j][0],2);
	}
	int a = f(0),b = f(1);
	if(min(a,b) < ans){
		printf("%d\n",min(a,b));
		int c = b < a;
		int x = n - 1,y = n - 1,idx = 0;
		while(x || y){
			if(nxt[x][y][c]){
				x--;
				out[idx++] = 'R';
			}
			else{
				y--;
				out[idx++] = 'D';
			}
		}
		reverse(out,out + idx);
		out[idx] = 0;
		puts(out);
	}
	else {
		puts("1");
		int i = 0,j = 0;
		for(;i < zerox;i++) putchar('D');
		for(;j < zeroy;j++) putchar('R');
		for(;i < n - 1;i++) putchar('D');
		for(;j < n - 1;j++) putchar('R');
		puts("");
	}	
	return 0;
}
