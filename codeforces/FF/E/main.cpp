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

const int MAX = 1e5 + 1e2;
int A[MAX],mark[MAX],n;
int B[MAX];

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",&A[i]),B[i] = A[i];
	int l = 0,ans = 0,can = 1;
	loop(r,n){
		if(l == r) {
			ans = max(ans,1);
			continue;
		}
		else{
			if(B[r] <= B[r - 1]){
				if(r - l){
					if(can){
						can = 0;
						if(r - l < 2 || B[r] > B[r - 2] + 1){
							B[r - 1] = ((r - 2 >= l) ? B[r - 2] : -1 )+ 1;
							mark[r - 1] = 1;
						}
						else {
							B[r] = B[r - 1] + 1;
							mark[r] = 1;
						}
					}
					else{
						can = 1;
						if(mark[l]) {
							mark[l] = 0;
							if(A[l] > B[l]) l++;
						}
						else{
							while(!mark[l+1])l++;
							if(B[l + 1] > A[l + 1]) {
								mark[l + 1] = 0;
								mark[l] = 1;
								B[l] = 0;
								B[l + 1] = A[l + 1];
								can = 0;
							}
							else {
								l++;
								mark[l] = 0;
								if(A[l] > B[l]) l++;
							}
						}
					}
				}
				else{
					if(can){
						can = 0;
						B[r - 1] = B[r] - 1;
						mark[r-1] = 1;
					}
					else{
						can = 1;
						l++;
					}
				}
				r--;
			}
			ans = max(ans,r - l + 1); 
		}
	//	cerr << l << " " << r << " " << can << " : ";
	//	for(int i = l;i <= r;i++) cerr << B[i] << " ";
	//	cerr << endl;
	}
	cout << ans << endl;
	//cerr << ans << endl;
	return 0;
}
