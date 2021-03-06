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
using namespace std;

const int MAX = 10000;
int S[MAX + 1];

int phi(int n){
	int i = 2,ans = n;
	while(i * i <= n){
		if(n%i == 0) ans = (ans * (i - 1))/i;
		while (n%i == 0) n /= i;
		i += 1;
	}
	if(n != 1) ans = (ans * (n - 1))/n;
	return ans;
}

int main(){
	pre();
	S[1] = 2;
	range(i,2,MAX) S[i] = S[i - 1] + phi(i);
	int T,N,K;
	cin >> T;
	while(T--){
		cin >> K >> N;
		int ans = 3*S[N] - 4;
		cout << K << " " << (ans >> (1 - (ans & 1))) << "/" << ((ans & 1) ? 2 : 1) << endl; 
	}
}
