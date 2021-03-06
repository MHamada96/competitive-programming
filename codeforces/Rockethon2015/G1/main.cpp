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

int A[6],n,k;
int B[6];
double ans = 0;
double tmp = 0;

int getInv(int *p){
	int ans= 0;
	loop(j,n) loop(i,j) ans += A[i] > A[j];
	return ans;
}

void generate(int k){
	if(k == 0) {
		ans += getInv(A);
		tmp++;
		return;
	}
	loop(j,n) loop(i,j + 1){
		reverse(A + i,A + j + 1);
		generate(k - 1);
		reverse(A + i,A + j + 1);
	}
}



int main(){
	scanf("%d %d",&n,&k);
	loop(i,n) scanf("%d",A + i);
	generate(k);
	ans /= tmp;
	printf("%.15f\n",ans);	
	return 0;
}
