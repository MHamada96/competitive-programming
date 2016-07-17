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

char G[8][10];
pi K,Q,N;

bool canAttack(pi x,pi y){
	range(dx,-2,2){
		for(int dy = -2;dy <= 2;dy++){
			if(abs(dx) + abs(dy) == 3){
				pi nX = x;
				nX.xx += dx;
				nX.yy += dy;
				if(nX == y) return 1;			
			}
		}
	}
	return 0;
}

int main(){
	loop(i,8) {
		scanf("%s",G[i]);
		loop(j,8){
			if(G[i][j] == 'K') K = mp(i,j);
			if(G[i][j] == 'N') N = mp(i,j);
			if(G[i][j] == 'Q') Q = mp(i,j);
		}
	}
	range(dx,-2,2){
		for(int dy = -2;dy <= 2;dy++){
			if(abs(dx) + abs(dy) == 3){
				pi nN = N;
				nN.xx += dx;
				nN.yy += dy;
				if(nN.xx < 0 || nN.xx >= 8 || nN.yy < 0 || nN.yy >= 8) continue;
				if(canAttack(nN,Q) && canAttack(nN,K)) {
					printf("YES %d%c\n",8-nN.xx,nN.yy + 'A');
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}