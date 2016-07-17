#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
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

const int MAX = 1 << 20;
int n,m,pos[MAX],val[MAX],off[MAX];
char command[5];


void process_commands(){
	vi ST;  int idx = 0;
	
	scanf("%d",&m);
	
	loop(i,m){
		scanf("%s",command);
		if(command[0] == 'D'){
			scanf("%d",pos + idx);
			if(!idx) val[idx] = pos[idx];
			else val[idx] = val[idx - 1] + pos[idx] - pos[idx - 1];
			pos[idx]++;	
			off[idx] = 0;
			ST.pb(idx++);
		}
		else{
			off[ST.back()]++;		
			ST.pop_back();
		}
	}
	m = idx;
}

void normalize(){
	int cummulative = 0;	
	loop(i,m) {
		cummulative += off[i];
		val[i] += cummulative;
	}
}

void solve(){	
	scanf("%d",&n);
	loop(i,n){
		int a; scanf("%d",&a);
		int p = upper_bound(pos,pos + m,a) - pos - 1;
		if(p == -1) printf("%d\n",a);
		else printf("%d\n",val[p] + a - pos[p]);
	}
}

int main(){
	process_commands();
	normalize();
	solve();
	return 0;
}
