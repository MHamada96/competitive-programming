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

string out [] ={"penalties","first","second"};

int main(){
	freopen("zamalek.in","r",stdin);
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&a,&b,&c,&d); swap(c,d);
		int first_won = (a > b) + (c > d),second_won = (a < b) + (c < d);
		if(first_won > second_won) puts(out[1].c_str());
		else if(first_won < second_won) puts(out[2].c_str());
		else if(a + c > b + d) puts(out[1].c_str());
		else if(a + c < b + d) puts(out[2].c_str());
		else{
			a = a + 2*c;
			b = 2*b + d;
			if(a > b) puts(out[1].c_str());
			else if(a < b) puts(out[2].c_str());
			else puts(out[0].c_str());
		}
	}
	return 0;
}
