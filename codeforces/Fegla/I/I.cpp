#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define vi vector<int>
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
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;


char nums[1000000][7];
int sum[1000000],ord[1000000];
int idx = 0;
char num[7];

void gen(int i,int d,int tot){
	if(i == d){
		sum[idx] = tot;
		num[d] = '\0';
		strcpy(nums[idx],num);
		idx++;	
		return;
	}
	loop(j,10){
		num[i] = j + '0';
		gen(i + 1,d,tot + j);
	}
}

bool cmp(const int & a,const int & b){
	if(sum[a] != sum[b]) return sum[a] < sum[b];	
	return strcmp(nums[a],nums[b]) < 0;
}
int ssum = 0;
bool cmp2(const int & a,const char *s){
	if(sum[a] != ssum) return sum[a] < ssum;
	return strcmp(nums[a],s) < 0;
}

int main(){
	int d,m;
	scanf("%d %d",&d,&m);
	gen(0,d,0);	
	loop(i,idx) ord[i] = i;
	sort(ord,ord + idx,&cmp);
	while(m--){
		int c,n;
		scanf("%d",&c);
		if(c == 1){
			scanf("%d",&n);
			printf("%s\n",nums[ord[n]]);
		} 
		else {
			scanf("%s",num);
			ssum = 0;
			loop(i,d) ssum += num[i] - '0';
			printf("%lu\n",lower_bound(ord,ord + idx,num,&cmp2) - ord);
		}
	}
	return 0;
}
