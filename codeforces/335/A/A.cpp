#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define print(A,t) cout << #A << ": "; copy(all(A),ostream_iterator<t>(cout," " )); cout << endl
#define pi pair<int,int>
#define point pi
#define vi vector<int>
#define ll long long
#define pl pair<ll,ll>
#define pre() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define prp(p) cout << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cout << #A << ": "; copy(A,A + n,ostream_iterator<t>(cout," " )); cout << endl
using namespace std;

int A[3],B[3],idx[3];
	
bool cmp(const int & a,const int & b){
	return A[a] - B[a] < A[b] - B[b];
}

int main(){
	while(scanf("%d",A) == 1){
		loop(i,2) scanf("%d",A + i + 1);
		loop(i,3) scanf("%d",B + i),idx[i] = i;
		sort(idx,idx + 3,&cmp);
		int a = idx[0],b = idx[1],c = idx[2];
		if(A[b] < B[b]){
			while(A[b] < B[b] && A[c] - 2 >= B[c]){
				A[b] += 1;
				A[c] -= 2;
			}
		}
		if(A[a] < B[a]){
			while(A[a] < B[a] && A[c] - 2 >= B[c]){
				A[a] += 1;
				A[c] -= 2;
			}
			while(A[a] < B[a] && A[b] - 2 >= B[b]){
				A[a] += 1;
				A[b] -= 2;
			}
		}
		if(A[a] >= B[a] && A[b] >= B[b] && A[c] >= B[c]) puts("Yes");
		else puts("No");
		
	} 
	return 0;
}
