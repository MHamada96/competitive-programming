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

#define aa xx.xx
#define bb xx.yy
#define cc yy.xx
#define zz yy.yy
typedef pair<pi,pi> line;
const int MAX = 3e5;
line A[MAX];
int n;

bool cmp(const line & l1,const line & l2){
	if(l1.aa == l2.aa && l1.bb == l2.bb) return l1.cc*1LL*l2.zz < l2.cc*1LL*l1.zz;
	if(l1.bb == 0 && l2.bb == 0) return l1.aa < l2.aa;
	else if(l1.bb == 0) return 0;
	else if(l2.bb == 0) return 1;
	if(l1.bb > 0 && l2.bb > 0) return l1.aa *1LL* l2.bb < l1.bb *1LL* l2.aa;
	if(l1.bb < 0 && l2.bb < 0) return l1.aa *1LL* l2.bb < l1.bb *1LL* l2.aa;
	return l1.aa *1LL* l2.bb > l1.bb *1LL* l2.aa;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		loop(i,n) {
			scanf("%d %d %d",&A[i].aa,&A[i].bb,&A[i].cc);
			int d = (A[i].aa || A[i].bb) ? __gcd(A[i].aa,A[i].bb) : 1;
			A[i].aa /= d;
			A[i].bb /= d;
			int dd = __gcd(A[i].cc,d);
			A[i].cc /= dd;
			A[i].zz = d/dd;
			if(A[i].zz < 0) A[i].zz *= -1,A[i].cc *= -1;
		}
		sort(A,A + n,&cmp);
		n = unique(A,A + n) - A;
		int ans = 0;
		loop(i,n){
			int j = i;
			while(j < n && A[i].aa == A[j].aa && A[i].bb == A[j].bb) j++;
			ans = max(ans,j - i);
			i = j - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
