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

char line[1 << 20];
char Z[1 << 20];

bool cond(int & x){
	int L = strlen(line); x = 0;
	if(line[0] != '1') return 0;
	for(int i = 1;i < L;i++) if(line[i] != '0') return 0; else x++;
	return 1;
}

int main(){
	int n,tot = 0,x ;		
	scanf("%d",&n); strcpy(Z,"1");
	while(scanf("%s",line) == 1){
		if(strcmp(line,"0") == 0) {
			puts("0");
			return 0;
		}
		if(cond(x)) tot += x;
		else {
			strcpy(Z,line);
		}
	}
	printf("%s",Z);
	loop(i,tot) putchar('0');
	puts("");
	return 0;
}
