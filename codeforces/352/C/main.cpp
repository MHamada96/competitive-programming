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

int ax,ay,bx,by,tx,ty;
int n;
pi A[1 << 20];
int B[1 << 20],C[1 << 20];
double DA[1 << 20],DB[1 << 20],DT[1 << 20];


inline double dist(const pi &  p,double a,double b){
	return hypot(p.xx - a,p.yy - b);
}

bool cmpA(const int & a,const int & b){
	return DA[a] - DT[a] < DA[b] - DT[b];
}

bool cmpB(const int & a,const int & b){
	return DB[a] - DT[a] < DB[b] - DT[b];
}

int main(){
	scanf("%d %d",&ax,&ay);
	scanf("%d %d",&bx,&by);
	scanf("%d %d",&tx,&ty);
	scanf("%d",&n);
	loop(i,n) {
		scanf("%d %d",&A[i].xx,&A[i].yy);
		B[i] = C[i] = i;
		DA[i] = dist(A[i],ax,ay);
		DB[i] = dist(A[i],bx,by);
		DT[i] = dist(A[i],tx,ty);
	}
	sort(B,B + n,&cmpA);
	sort(C,C + n,&cmpB);
	//prArr(B,n,int);
	//prArr(C,n,int);	
	
	double tmp = 0;
	loop(i,n) tmp += 2*DT[i];
	double ans = tmp + min(hypot(ax - tx,ay - ty),hypot(bx - tx,by - ty));
	loop(i,6) {
	loop(j,6){
		if(i < 5 && j < 5 && B[i] == C[j]) continue;
		double tmp2 = tmp,d1 = 0,d2 = 0; bool c = 0;
		if(i != 5 && i < n){
			c = 1;
			d1 = DT[B[i]] - DA[B[i]];
		}
		if(j != 5 && j < n){
			c = 1;
			d2 = DT[C[j]] - DB[C[j]];
		}
		tmp2 = tmp - d1 - d2;
		if(c) ans = min(ans,tmp2);
	}	
	//cerr << endl;
	}	
	printf("%.12f\n",ans);
	return 0;
}
