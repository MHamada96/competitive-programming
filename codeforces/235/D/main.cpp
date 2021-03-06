#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
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

const int MAX = 1e5 + 1e2;
double f[MAX],p[MAX];
int n;

int main(){
	scanf("%d",&n);
	double S = 0,E1 = 0,E2 = 0,SP = 0;
	range(j,1,n){
		scanf("%lf",p + j);
		double P = p[j],tmp = 0;
		f[j] = (1 - p[j]) * f[j - 1];
		E2 = p[j] * (E2 + SP + 2*E1 + 1 - p[j - 1]);
		E1 = p[j] * (E1 + SP + 1 - p[j - 1]);
		SP = p[j] * (SP + 1 - p[j - 1]);
		f[j] += S * p[j] + E2;
		S = S * p[j] + f[j - 1] * (1 - p[j]);
	}	
	printf("%.10f\n",f[n]);
	cerr << f[n] << endl;
	return 0;
}
