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

char line[1 << 20],sub[1 << 20],helper[10];
int CTR[10],n,m;
int tmpCTR[10];

int putnext(int c){
	loop(i,10) if(CTR[i]) {
		if(c && i == 0) continue;
		CTR[i]--;
		putchar(i + '0');
		break;
	}	
}
int getnext(int c){
	loop(i,10) 
	if(CTR[i]) {
		if(c && i == 0) continue;
		return i;
	}
	return 10;
}

int main(){
	scanf("%s %s",line,sub);
	m = strlen(line);
	n = strlen(sub);
	loop(i,m) CTR[line[i] - '0']++;
	loop(i,n) CTR[sub[i] - '0']--;
	int k = 1;	
	while(k < m) {
		sprintf(helper,"%d",k);
		int L = strlen(helper);
		if(k == m - L){
			int c = 1;
			copy(CTR,CTR + 10,tmpCTR);
			loop(i,L){
				tmpCTR[helper[i] - '0']--;
				c &= tmpCTR[helper[i] - '0'] >= 0;
			}
			if(c) break;
		}
		k++;
	}
	copy(tmpCTR,tmpCTR + 10,CTR);
	bool c = 1; char *p = sub;
	if(n && sub[0] == '0'){
		if(k == 1){
			puts("0");
			return 0;
		}
		putnext(c);
		c = 0;	
	}
	while(*p){
		int z = 1;
		while(getnext(c) < (*p - '0')){
			putnext(c);
			c = 0;
			z = 0;
		}
		if(z && getnext(c) != (*p - '0')) break;
		p++;
	}
	printf("%s",sub);
	c = strlen(sub) == 0;
	while(getnext(c) != 10) {
		putnext(c);
		c = 0;
	}
	puts("");
	return 0;
}

