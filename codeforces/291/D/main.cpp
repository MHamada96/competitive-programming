#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
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

const int MAX = 1e5 + 1e3;
int A[MAX][6],n,m,k;
int tot = 0;
int ans[6],mxL = 0;
deque<int> mxH[6];

void insert(int a,deque<int> & dq,int & tot){
	if(!dq.empty()) tot -= A[dq.front()/m][dq.front()%m];
	while(!dq.empty() && A[dq.back()/m][dq.back()%m] <= A[a/m][a%m]) dq.pop_back();
	dq.pb(a);
	tot += A[dq.front()/m][dq.front()%m];
}

void erase(int a,deque<int> & dq,int & tot){
	if(dq.front() != a || dq.empty()) return;
	tot -= A[dq.front()/m][dq.front()%m];
	dq.pop_front();
	if(!dq.empty()) tot += A[dq.front()/m][dq.front()%m];
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	loop(i,n) loop(j,m) scanf("%d",&A[i][j]);
	int l = 0;
	loop(i,n){
		loop(j,m) insert(i*m + j,mxH[j],tot);
		while(l <= i && tot > k) {
			loop(j,m) erase(l*m + j,mxH[j],tot);
			l++;
		}
		if(i - l + 1 > mxL){
			mxL = i - l + 1;
			loop(j,m) ans[j] = A[mxH[j].front()/m][mxH[j].front()%m];
		}
	//	cerr << "from " << l << " to " << i << " tot = " << tot << endl << "mxH : ";
	//	loop(j,m) cerr << A[mxH[j].front()/m][mxH[j].front()%m] << " " ;
	//	cerr << endl;
	}
	//cerr << mxL << endl;
	//prArr(ans,m,int);
	loop(j,m) printf("%d%c",ans[j]," \n"[j == m - 1]);
	return 0;
}
