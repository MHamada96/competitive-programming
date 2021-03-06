#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
#define vp vector<pair<int,int> >
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

int n,m,Q;
char G[50];
int A[50][50];
int IS[50][50][50][50];
int CTR[50][50][50][50];

	
int main(){
	scanf("%d %d %d",&m,&n,&Q);
	loop(i,m){
		scanf("%s",G);
		loop(j,n) A[i][j] = (G[j] == '0') + (i ? A[i-1][j] : 0) + (j ? A[i][j-1] : 0) - ((i&&j) ? A[i-1][j-1] : 0);
	}
	loop(x1,m) range(x2,x1,m-1) loop(y1,n) range(y2,y1,n-1) {
		int s = A[x2][y2] - (x1 ? A[x1-1][y2] : 0) - (y1 ? A[x2][y1-1] : 0) + ((x1&&y1) ? A[x1-1][y1-1] : 0);
		if(s == (x2-x1+1)*(y2-y1+1)) IS[x1][y1][x2][y2] = 1;
	}
	loop(x1,m) range(x2,x1,m-1) loop(y1,n) range(y2,y1,n-1){
		if(y2 - y1) CTR[x1][y1][x2][y2] += CTR[x1][y1][x2][y2 - 1];	
		if(x2 - x1) CTR[x1][y1][x2][y2] += CTR[x1][y1][x2 - 1][y2];
		if(y2 - y1 && x2 - x1) CTR[x1][y1][x2][y2] -= CTR[x1][y1][x2 - 1][y2 - 1];
		range(i,x1,x2) range(j,y1,y2) CTR[x1][y1][x2][y2] += IS[i][j][x2][y2];
//		fprintf(stderr,"f(%d,%d,%d,%d) = %d\n",x1,y1,x2,y2,CTR[x1][y1][x2][y2]);
	}
	while(Q--){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--,b--,c--,d--;
		printf("%d\n",CTR[a][b][c][d]);
//		cerr << 	CTR[a][b][c][d] << endl;
	}
	return 0;
}
