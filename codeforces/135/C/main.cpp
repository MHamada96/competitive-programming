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

#define c2d(c) (c - 'A')
const int MAX = 5e5 + 1e2;

int L,k;
char line[MAX];
int cnt[MAX];

void solve_special(){
	int cnt[2] = {0},q = 0;
	loop(i,L) {
		if(c2d(line[i]) != q) cnt[0]++;
		else cnt[1]++;
		q ^= 1;
	}
	q = cnt[0] > cnt[1];
	printf("%d\n",min(cnt[0],cnt[1]));
	loop(i,L) putchar(q + 'A'),q ^= 1;
	puts("");
}

char pick(char a,char b){
	loop(i,k) if(i != c2d(a) && i != c2d(b)) return i + 'A';
}

void solve(){
	int ans = 0;
	loop(i,L - 1){
		if(line[i] == line[i + 1]){
			line[i + 1] = pick(line[i],line[i + 2]);
			ans++;
		}
	}	
	printf("%d\n",ans);
	puts(line);
}	

int main(){
	scanf("%d %d",&L,&k);
	scanf("%s",line);
	if(k == 2) solve_special();
	else solve();
	return 0;
}
