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

string I[1 << 10][2];
int score[1 << 10];
int N;

int solve(){
	fill(score,score + N,2);
	set<string> F,S;
	int ctr = 0,ans = 0;
	loop(k,N){
		fill(score,score + N,2);
		F.clear(); S.clear();
		ctr = 1;
		F.insert(I[k][0]); 
		S.insert(I[k][1]);
		score[k] = 0;	
		loop(i,N){
			int p = max_element(score,score + N) - score;
			if(score[p]) ctr++;
			if(F.find(I[p][0]) == F.end()){
				loop(j,N){
					if(I[p][0] == I[j][0]) score[j]--;
				}
			}			
			if(S.find(I[p][1]) == S.end()){
				loop(j,N){
					if(I[p][1] == I[j][1]) score[j]--;
				}
			}		
			F.insert(I[p][0]);
			S.insert(I[p][1]);
		}
		cerr << ctr << endl;
		ans = max(ans,N - ctr);
	}
	return ans;
}

int main(){
	pre();
	int T;
	cin >> T;
	loop(t,T){
		cin >> N;
		loop(i,N) loop(j,2) cin >> I[i][j];
		printf("Case #%d: %d\n",t + 1,solve());	
	}
	return 0;
}