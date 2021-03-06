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

int out[1 << 20];

int main(){
	int n,m;
	scanf("%d %d",&n,&m); 
	int ctr1 = 0,ctr2 = 1;
	loop(i,m){
		int a,b;
		scanf("%d",&a);
		if(a == 1){
			scanf("%d",&b);
			ctr1 += b;
			ctr2 += b;
			ctr1 = (ctr1%n + n)%n;
			ctr2 = (ctr2%n + n)%n;
		}
		else {
			if(ctr1 & 1) ctr1--;
			else ctr1++;
			if(ctr1 == n + 1) ctr1 = 1;
			if(ctr1 == -1) ctr1 = n;

			if(ctr2 & 1) ctr2--;
			else ctr2++;
			if(ctr2 == n + 1) ctr2 = 1;
			if(ctr2 == -1) ctr2 = n;	
		}
	}	
	loop(i,n){
		int p = 2*(i/2);
		if(i & 1) p += ctr2;
		else p += ctr1;
		p = (p%n + n)%n;
		out[p] = i + 1; 
	}
	loop(i,n) printf("%d%s",out[i],(i == n - 1) ? "\n" : " "); 	
	return 0;
}

