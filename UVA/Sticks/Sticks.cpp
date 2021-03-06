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

vi L,taken;
int N;

bool possibe(int idx,int tot,int cur,int l,int n){
	if(tot == l){
		if(cur + 1 == n) return 1;
		return possibe(0,0,cur + 1,l,n);
	}
	if(tot > l || idx == N) return 0;
	if(!taken[idx]){	
		taken[idx] = 1;
		if(tot + L[idx] <= l && possibe(idx + 1,tot + L[idx],cur,l,n)) return 1;
		taken[idx] = 0;
		++idx;
		while(idx < N && L[idx] == L[idx - 1]) idx++;
		return possibe(idx,tot,cur,l,n);
	}
	else return possibe(idx + 1,tot,cur,l,n);
}

int main(){
	while(scanf("%d",&N) == 1 && N){
		int sum = 0,ans = INT_MAX,cmax = 0;
		L.resize(N);
		taken.resize(N);
		loop(i,N) {
			scanf("%d",&L[i]);
			sum += L[i];
			cmax = max(cmax,L[i]);
			taken[i] = 0;
		}
		sort(all(L));
		for(int i = sum;i>=1;i--){
			if(sum%i == 0){
				int l = sum/i,n = i;
				if(l >= cmax){
					fill(all(taken),0);
					bool c = possibe(0,0,0,l,n);
					if(c){
						ans = l;
						break;
					} 
				}		
			}
		}
		printf("%d\n",ans);
	}  	
	return 0;
}
