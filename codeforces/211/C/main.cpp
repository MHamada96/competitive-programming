#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,L = (n);i < L;i++)
#define range(i,a,b) for(int i = (a),L = (b);i <= L;i++)
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

char A[200000 + 1],B[200000 + 1];


int main(){
	cin >> A;
	int n = strlen(A),idx = 0;
	loop(i,n){
		B[idx++] = A[i];
		int j = i;
		while(j < n && A[i] == A[j]) j++;
		if(j - i <= 2) continue;
		else i = j - 2;
	}
	cerr << B << endl;
	n = idx; idx = 0;
	loop(i,n){
		A[idx++] = B[i];
		if(i < n - 3){
			if(B[i] == B[i + 1] && B[i + 2] == B[i + 3]) {
				A[idx++] = B[i + 1];
				A[idx++] = B[i + 2];		
				i = i + 3;
			}
		}
	}
	A[idx] = 0;
	puts(A);
	return 0;
}
