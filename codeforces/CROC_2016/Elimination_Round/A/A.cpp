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

char A[2][3],B[2][3];
char out[2][5] = {"NO","YES"};
set<string> S;
int di[] = {0,0,-1,1},dj[] = {-1,1,0,0};


bool equal(){
	loop(i,2) loop(j,2) if(A[i][j] != B[i][j]) return 0;
	return 1;
}

bool vis(){
	string s = string(A[0]) + "$" + string(A[1]);
	if(S.find(s) != S.end()) return 1;
	S.insert(s);
	return 0;
}

bool f(){
	if(equal()) return 1;
	if(vis()) return 0;
	
	loop(i,2) loop(j,2){
		loop(k,4){
			int ni = i + di[k];
			int nj = j + dj[k];
			if(ni == -1 || nj == -1 || ni == 2 || nj == 2) continue;
			if(A[ni][nj] == 'X'){
				swap(A[i][j],A[ni][nj]);
				if(f()) return 1;
				swap(A[i][j],A[ni][nj]);
			}
		}
	}
	return 0;
}


int main(){
	loop(i,2) scanf("%s",A[i]);
	loop(i,2) scanf("%s",B[i]);
	puts(out[f()]);
	return 0;
}
